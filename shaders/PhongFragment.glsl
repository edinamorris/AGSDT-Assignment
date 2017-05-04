#version 330 core
// this is a pointer to the current 2D texture object
uniform sampler2D tex;
const int numberLights=2;
uniform vec3 light[numberLights];
uniform vec4 lightDiffuse;
uniform bool particle;
// the vertex UV
in vec2 vertUV;
in vec3 normal;
// the final fragment colour
layout (location =0) out vec4 outColour;
void main ()
{
    outColour=vec4(0.1);
    vec3 N=normalize(normal);

    float totalLight=0.1;

    vec3 L[numberLights];
    for(int i=0; i<numberLights; i++)
    {
        L[i]=normalize(light[i]);
        float dotProduct=dot(L[i],N);
        totalLight+=dotProduct;
    }
    if(totalLight>1.0)
    {
        totalLight=1.0;
    }
    else if(totalLight<0.1)
    {
        totalLight=0.1;
    }

    if(particle==true)
    {
        totalLight=1.0;
    }

    // set the fragment colour to the current texture with light influence
    outColour += (texture(tex,vertUV)) * lightDiffuse * (totalLight);
}
