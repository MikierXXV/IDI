#version 330 core

in vec3  fmatamb;
in vec3  fmatdiff;
in vec3  fmatspec;
in float fmatshin;
in vec3  fvertex;
in vec3  fnormal;

uniform mat4 TGpat;

uniform vec3 posFocus1;
uniform vec3 colFocus1;

uniform vec3 posFocus2;
uniform vec3 colFocus2;

uniform vec3 posFocus3;
uniform vec3 colFocus3;


const vec3 llumAmbient = vec3(0.2, 0.2, 0.2);


uniform mat4 TG;
uniform mat4 Proj;
uniform mat4 View;

out vec4 FragColor;


vec3 Ambient() {
  return llumAmbient*fmatamb;
}

vec3 Lambert (vec3 NormSCO, vec3 L, vec3 colorFocus)
{
  // Fixeu-vos que SOLS es retorna el terme de Lambert!
  // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats
  vec3 colorRes = vec3(0);
  if (dot (L, NormSCO) > 0)
    colorRes = colorFocus * fmatdiff * dot (L, NormSCO);
  return (colorRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec3 vertSCO, vec3 colorFocus)
{
  // Fixeu-vos que SOLS es retorna el terme especular!
  // Assumim que els vectors estan normalitzats
  vec3 colorRes = vec3 (0);
  // Si la llum ve de darrera o el material és mate no fem res
  if ((dot(NormSCO,L) < 0) || (fmatshin == 0))
    return colorRes;  // no hi ha component especular

  vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
  vec3 V = normalize(-vertSCO); // perquè la càmera està a (0,0,0) en SCO

  if (dot(R, V) < 0)
    return colorRes;  // no hi ha component especular

  float shine = pow(max(0.0, dot(R, V)), fmatshin);
  return (colorRes + fmatspec * colorFocus * shine);
}

void main()
{
    vec3 color = Ambient();
    vec3 f1 = (vec4(posFocus1,1.0)).xyz;
    vec3 f2 = (View * vec4(posFocus2, 1.0)).xyz;
    vec3 f3 = (View * TGpat * vec4(posFocus3, 1.0)).xyz;

    vec3 L1 = normalize(f1 - fvertex);
    vec3 L2 = normalize(f2 - fvertex);
    vec3 L3 = normalize(f3 - fvertex);

    color += Phong (fnormal, L1, fvertex, colFocus1) + Lambert(fnormal, L1, colFocus1) + Phong (fnormal, L2, fvertex, colFocus2) + Lambert(fnormal, L2, colFocus2) + Phong (fnormal, L3, fvertex, colFocus3) + Lambert(fnormal, L3, colFocus3);
    
    FragColor = vec4(color, 1);
}
