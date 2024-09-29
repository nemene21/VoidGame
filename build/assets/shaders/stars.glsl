#version 100
precision mediump float;

varying vec2 fragTexCoord;
uniform sampler2D texture0;
uniform float time;

void main()
{
    vec4 pixel;
    for (float i = 3.0; i >= 0.0; i--) {
        vec2 offset = vec2(i * 0.25, time * i * 0.01);

        pixel = texture2D(texture0, fragTexCoord + offset);
        if (pixel.a > 0.1) {
            gl_FragColor = pixel;
            gl_FragColor.rgb /= 4.0 - i;
        }
    }
    gl_FragColor.rgb *= 0.2;
}