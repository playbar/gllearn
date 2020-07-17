#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in float rc;

in vec3 fragPosition;
in vec3 fragNormal;

uniform mat4 view;
uniform sampler2D texture_diffuse1;

void main()
{
    vec4 color = vec4(0.5, 0.3, 0.6, 1.0);
    vec3 n = normalize(mat3(view) * fragNormal);
    vec3 p = vec3(view * vec4(fragPosition, 1.0));
    vec3 v = normalize(-p);
    float vdn = max(dot(v, n), 0.0);



//    FragColor.a = 1.0;
//    FragColor.rgb = vec3(smoothstep(0.6, 1.0, vdn));
//    FragColor.a = 1.0;
//    FragColor.rgb = vec3(vdn) * (fragNormal * 0.5 + 0.5);
//    float rimsmooth = smoothstep( 0, 1.0, rc);
    vec4 color1 = texture(texture_diffuse1, TexCoords);
//    FragColor.rgb = FragColor.rgb + vec3(smoothstep(0.6, 1.0, vdn));

//    FragColor.rgb = FragColor.rgb * smoothstep(0.0, 1.0, vdn);
    FragColor = mix(color, color1, smoothstep(0.0, 1.0, vdn));
//    FragColor = FragColor;
}

