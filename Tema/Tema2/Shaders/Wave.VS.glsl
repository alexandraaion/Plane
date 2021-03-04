#version 330

layout(location = 0) in vec3 v_position;

uniform mat4 Model;
uniform mat4 View;
uniform mat4 Projection;
uniform float time;

out float wave_height;

void main()
{
    float move_y = sin(time + v_position.x);
    vec3 new_pos = v_position + vec3(cos(time + v_position.x) * 0.1, move_y, cos(time + v_position.x - v_position.y) * 0.1);

    wave_height =  v_position.y - new_pos.y;

	gl_Position = Projection * View * Model * vec4(new_pos, 1.0);
}
