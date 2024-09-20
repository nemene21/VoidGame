#version 100
precision mediump float;

varying vec2 fragTexCoord;
uniform sampler2D texture0;
uniform float time;
uniform float flash;

void main()
{
    gl_FragColor = texture2D(texture0, fragTexCoord);
    gl_FragColor.rgb = gl_FragColor.rgb + (vec3(1, 1, 1) - gl_FragColor.rgb) * flash;
}