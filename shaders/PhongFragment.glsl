#version 330 core
// this is a pointer to the current 2D texture object
uniform sampler2D tex;
uniform vec3 lightPos;
uniform vec4 lightDiffuse;
// the vertex UV
in vec2 vertUV;
in vec3 normal;
// the final fragment colour
layout (location =0) out vec4 outColour;
void main ()
{
    vec3 N=normalize(normal);

    // The Light source vector
    vec3 L = normalize(lightPos);

    // set the fragment colour to the current texture
    outColour = (texture(tex,vertUV));
}
