//
// Created by ryanm on 2/9/2021.
//

const char* vertexShaderCode =
        "#version 460\r\n"
        ""
        "in layout(location=0) vec2 position;"
        ""
        "void main()"
        "{"
        "  gl_Position = vec4(position, 0.0, 1.0);"
        "}" ;


const char* fragmentShaderCode =
        "#version 460\r\n"
        ""
        "out vec4 daColor;"
        ""
        "void main()"
        "{"
        "   daColor = vec4(0.0, 1.0, 0.0, 1.0);"
        "}";