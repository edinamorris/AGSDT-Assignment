#version 330 core
/// @brief flag to indicate if model has unit normals if not normalize
uniform bool Normalize;
/// @brief MVP passed from app
uniform mat4 MVP;
// first attribute the vertex values from our VAO
layout (location=0) in vec3 inVert;
// second attribute the UV values from our VAO
layout (location=1)in vec2 inUV;
// normal values
layout(location=2) in vec3 inNormal;

// we use this to pass the UV values to the frag shader
out vec2 vertUV;

out vec3 normal;
// our normal matrix
uniform mat3 normalMatrix;

void main()
{
// pre-calculate for speed we will use this a lot

    // calculate the vertex position
    gl_Position = MVP*vec4(inVert, 1.0);
    // pass the UV values to the frag shader
    vertUV=inUV.st;

    normal=(inNormal*normalMatrix);

    // if set normalize the fragment
    if (Normalize == true)
    {
      normal = normalize(normal);
    }
}
