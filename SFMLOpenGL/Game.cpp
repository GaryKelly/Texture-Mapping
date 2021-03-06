#include <Game.h>

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube Texturing")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

#if (DEBUG >= 2)
		DEBUG_MSG("Game running...");
#endif

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[4];
	float texel[2];
} Vertex1;

float vertices[]
{
	-0.2,-0.2,0.2, //t1
	-0.2,-0.2,-0.2,
	-0.2,0.2,-0.2, //t1 end
	0.2,0.2,0.2,   //t2
	-0.2,-0.2,0.2,
	-0.2,0.2,0.2,  //t2 end
	0.2,-0.2,-0.2, //t3
	-0.2,-0.2,0.2,
	0.2,-0.2,0.2,  //t3 end
	0.2,-0.2,0.2,  //t4
	0.2,0.2,0.2,
	-0.2,-0.2,0.2, //t4 end
	-0.2,-0.2,0.2, //t5
	-0.2,0.2,-0.2,
	-0.2,-0.2,0.2, //t5 end
	0.2,-0.2,-0.2, //t6
	-0.2,-0.2,-0.2,
	-0.2,-0.2,0.2, //t6 end
	-0.2,0.2,-0.2, //t7
	-0.2,-0.2,0.2,
	0.2,-0.2,-0.2, //t7 end
	0.2,0.2,-0.2,  //t8
	0.2,-0.2,0.2,
	0.2,0.2,0.2,   //t8 end
	0.2,-0.2,0.2,  //t9
	0.2,0.2,-0.2,
	0.2,-0.2,-0.2, //t9 end
	0.2,0.2,-0.2,  //t10
	0.2,0.2,0.2,
	-0.2,0.2,0.2,  //t10 end
	0.2,0.2,-0.2,  //t11
	-0.2,0.2,0.2,
	-0.2,0.2,-0.2, //t11 end
	0.2,0.2,-0.2   //t12
	- 0.2,0.2,-0.2,
	0.2,-0.2,-0.2  //t12 end
};

Vertex1 vertex[36];
Vertex1 newVerts[36];
GLubyte triangles[36];

/* Variable to hold the VBO identifier and shader data */
GLuint	index,		//Index to draw
		vsid,		//Vertex Shader ID
		fsid,		//Fragment Shader ID
		progID,		//Program ID
		vao = 0,	//Vertex Array ID
		vbo[1],		// Vertex Buffer ID
		positionID, //Position ID
		colorID,	// Color ID
		to,			// Texture ID 1 to 32
		textureID,	//Texture ID
		texelID;	// Texel ID

//const string filename = "texture.tga";
//const string filename = "cube.tga";
//const string filename = "minecraft.tga";
const string filename = "texture.tga";
//const string filename = "Untitled.tga";

int width; //width of texture
int height; //height of texture
int comp_count; //Component of texture
const int number = 4; //4 = RGBA

unsigned char* img_data;

void Game::initialize()
{
	isRunning = true;
	GLint isCompiled = 0;
	GLint isLinked = 0;

	glewInit();

	DEBUG_MSG(glGetString(GL_VENDOR));
	DEBUG_MSG(glGetString(GL_RENDERER));
	DEBUG_MSG(glGetString(GL_VERSION));

	/* Vertices counter-clockwise winding */
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			vertex[i].coordinate[j] = vertices[i * 3 + j];
			vertex[i].color[j] = (((j + 1)*(0.5 + 1)) / 100.0);
		}
		
	}

	vertex[0].texel[0] = 0.0f;
	vertex[0].texel[1] = 0.0f;

	vertex[1].texel[0] = 1.0f;
	vertex[1].texel[1] = 1.0f;

	vertex[2].texel[0] = 1.0f;
	vertex[2].texel[1] = 0.0f;

	vertex[3].texel[0] = 0.0f;
	vertex[3].texel[1] = 0.0f;

	vertex[4].texel[0] = 0.0f;
	vertex[4].texel[1] = 1.0f;

	vertex[5].texel[0] = 0.0f;
	vertex[5].texel[1] = 1.0f;
	vertex[6].texel[0] = 0.0f;
	vertex[6].texel[1] = 0.0f;

	vertex[7].texel[0] = 1.0f;
	vertex[7].texel[1] = 1.0f;

	vertex[8].texel[0] = 1.0f;
	vertex[8].texel[1] = 0.0f;

	vertex[9].texel[0] = 0.0f;
	vertex[9].texel[1] = 0.0f;

	vertex[10].texel[0] = 0.0f;
	vertex[10].texel[1] = 1.0f;

	vertex[11].texel[0] = 0.0f;
	vertex[11].texel[1] = 1.0f;
	vertex[12].texel[0] = 0.0f;
	vertex[12].texel[1] = 0.0f;

	vertex[13].texel[0] = 1.0f;
	vertex[13].texel[1] = 1.0f;

	vertex[14].texel[0] = 1.0f;
	vertex[14].texel[1] = 0.0f;

	vertex[15].texel[0] = 0.0f;
	vertex[15].texel[1] = 0.0f;

	vertex[16].texel[0] = 0.0f;
	vertex[16].texel[1] = 1.0f;

	vertex[17].texel[0] = 0.0f;
	vertex[17].texel[1] = 1.0f;
	vertex[18].texel[0] = 0.0f;
	vertex[18].texel[1] = 0.0f;

	vertex[19].texel[0] = 1.0f;
	vertex[19].texel[1] = 1.0f;

	vertex[20].texel[0] = 1.0f;
	vertex[20].texel[1] = 0.0f;

	vertex[21].texel[0] = 0.0f;
	vertex[21].texel[1] = 0.0f;

	vertex[22].texel[0] = 0.0f;
	vertex[22].texel[1] = 1.0f;

	vertex[23].texel[0] = 0.0f;
	vertex[23].texel[1] = 1.0f;
	vertex[24].texel[0] = 0.0f;
	vertex[24].texel[1] = 0.0f;

	vertex[25].texel[0] = 1.0f;
	vertex[25].texel[1] = 1.0f;

	vertex[26].texel[0] = 1.0f;
	vertex[26].texel[1] = 0.0f;

	vertex[27].texel[0] = 0.0f;
	vertex[27].texel[1] = 0.0f;

	vertex[28].texel[0] = 0.0f;
	vertex[28].texel[1] = 1.0f;

	vertex[29].texel[0] = 0.0f;
	vertex[29].texel[1] = 1.0f;
	vertex[30].texel[0] = 0.0f;
	vertex[30].texel[1] = 0.0f;

	vertex[31].texel[0] = 1.0f;
	vertex[31].texel[1] = 1.0f;

	vertex[32].texel[0] = 1.0f;
	vertex[32].texel[1] = 0.0f;

	vertex[33].texel[0] = 0.0f;
	vertex[33].texel[1] = 0.0f;

	vertex[34].texel[0] = 0.0f;
	vertex[34].texel[1] = 1.0f;

	vertex[35].texel[0] = 0.0f;
	vertex[35].texel[1] = 1.0f;
	
	/*Index of Poly / Triangle to Draw */
	for (int i = 0; i < 36; i++)
	{
		triangles[i] = i;
	}

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex1) * 36, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 36, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	/* Vertex Shader which would normally be loaded from an external file */
	std::ifstream vertShadText("VertexShader.txt");
	if (!vertShadText)
	{
		std::cout << "error loading text file" << std::endl;

	}
	std::string vertShadString((std::istreambuf_iterator<char>(vertShadText)), std::istreambuf_iterator<char>());
	const char* vs_src = vertShadString.c_str(); ; //Vertex Shader Src

	DEBUG_MSG("Setting Up Vertex Shader");

	vsid = glCreateShader(GL_VERTEX_SHADER); //Create Shader and set ID
	glShaderSource(vsid, 1, (const GLchar**)&vs_src, NULL); // Set the shaders source
	glCompileShader(vsid); //Check that the shader compiles

	//Check is Shader Compiled
	glGetShaderiv(vsid, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_TRUE) {
		DEBUG_MSG("Vertex Shader Compiled");
		isCompiled = GL_FALSE;
	}
	else
	{
		DEBUG_MSG("ERROR: Vertex Shader Compilation Error");
	}
	std::ifstream fragShadText("FragShader.txt");
	if (!fragShadText)
	{
		std::cout << "Error Loading text file" << std::endl;
	}
	std::string fragShaderString((std::istreambuf_iterator<char>(fragShadText)), std::istreambuf_iterator<char>());
	/* Fragment Shader which would normally be loaded from an external file */
	const char* fs_src = fragShaderString.c_str();

	DEBUG_MSG("Setting Up Fragment Shader");

	fsid = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fsid, 1, (const GLchar**)&fs_src, NULL);
	glCompileShader(fsid);
	//Check is Shader Compiled
	glGetShaderiv(fsid, GL_COMPILE_STATUS, &isCompiled);

	if (isCompiled == GL_TRUE) {
		DEBUG_MSG("Fragment Shader Compiled");
		isCompiled = GL_FALSE;
	}
	else
	{
		DEBUG_MSG("ERROR: Fragment Shader Compilation Error");
	}

	DEBUG_MSG("Setting Up and Linking Shader");
	progID = glCreateProgram();	//Create program in GPU
	glAttachShader(progID, vsid); //Attach Vertex Shader to Program
	glAttachShader(progID, fsid); //Attach Fragment Shader to Program
	glLinkProgram(progID);

	//Check is Shader Linked
	glGetProgramiv(progID, GL_LINK_STATUS, &isLinked);

	if (isLinked == 1) {
		DEBUG_MSG("Shader Linked");
	}
	else
	{
		DEBUG_MSG("ERROR: Shader Link Error");
	}

	// Use Progam on GPU
	// https://www.opengl.org/sdk/docs/man/html/glUseProgram.xhtml
	glUseProgram(progID);

	img_data = stbi_load(filename.c_str(), &width, &height, &comp_count, 4);

	if (img_data == NULL)
	{
		DEBUG_MSG("ERROR: Texture not loaded");
	}

	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &to);
	glBindTexture(GL_TEXTURE_2D, to);

	//Wrap around
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexParameter.xml
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Filtering
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexParameter.xml
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//Bind to OpenGL
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glTexImage2D.xml
	glTexImage2D(GL_TEXTURE_2D, //2D Texture Image
		0, //Mipmapping Level 
		GL_RGBA, //GL_RED, GL_GREEN, GL_BLUE, GL_ALPHA, GL_RGB, GL_BGR, GL_RGBA 
		width, //Width
		height, //Height
		0, //Border
		GL_RGBA, //Bitmap
		GL_UNSIGNED_BYTE, img_data);

	// Find variables in the shader
	//https://www.khronos.org/opengles/sdk/docs/man/xhtml/glGetAttribLocation.xml
	positionID = glGetAttribLocation(progID, "sv_position");
	colorID = glGetAttribLocation(progID, "sv_color");
	texelID = glGetAttribLocation(progID, "sv_texel");
	textureID = glGetUniformLocation(progID, "f_texture");
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	//Change vertex data
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}
//Rotate on Z clockwise.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		m_rotationAngleZ += 0.0005f;

		if (m_rotationAngleZ > 360.0f)
		{
			m_rotationAngleZ -= 360.0f;
		}
	}

	//Rotate on X clockwise.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{

		m_rotationAngleX += 0.0005f;

		if (m_rotationAngleX > 360.0f)
		{
			m_rotationAngleX -= 360.0f;
		}
	}

	//Rotate on Y clockwise
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		m_rotationAngleY += 0.0005f;

		if (m_rotationAngleY > 360.0f)
		{
			m_rotationAngleY -= 360.0f;
		}
	}

	for (int i = 0; i < 36; i++)
	{
		//Assigne the initial vertex to a tempory vector
		MyVector3 tempVect{ vertex[i].coordinate[0], vertex[i].coordinate[1], vertex[i].coordinate[2] };

		tempVect = MyMatrix3::rotationX(m_rotationAngleX) * tempVect;
		tempVect = MyMatrix3::rotationY(m_rotationAngleY) * tempVect;
		tempVect = MyMatrix3::rotationZ(m_rotationAngleZ) * tempVect;
		

		newVerts[i].coordinate[0] = tempVect.x;
		newVerts[i].coordinate[1] = tempVect.y;
		newVerts[i].coordinate[2] = tempVect.z;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
	{

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
	}
#if (DEBUG >= 2)
	DEBUG_MSG("Update up...");
#endif

}

void Game::render()
{

#if (DEBUG >= 2)
	DEBUG_MSG("Drawing...");
#endif

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex1) * 36, newVerts , GL_STATIC_DRAW);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain
		model components that 'are' and 'are not' to be drawn )	*/

	//Set Active Texture .... 32
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(textureID, 0);

	// Set pointers for each parameter
	// https://www.opengl.org/sdk/docs/man4/html/glVertexAttribPointer.xhtml
	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex1), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex1), (void*)(3*sizeof(float)));
	glVertexAttribPointer(texelID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex1), (void*)(7 * sizeof(float)));

	//Enable Arrays
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	glEnableVertexAttribArray(texelID);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	window.display();

}

void Game::unload()
{
#if (DEBUG >= 2)
	DEBUG_MSG("Cleaning up...");
#endif
	glDeleteProgram(progID);
	glDeleteBuffers(1, vbo);
	stbi_image_free(img_data); //Free image
}

void Game::rotate(int t_axis)
{
	MyMatrix3 m_rotateX = MyMatrix3::rotationX(0.001);
	MyMatrix3 m_rotateY = MyMatrix3::rotationY(0.001);
	MyMatrix3 m_rotateZ = MyMatrix3::rotationZ(0.001);
	MyMatrix3 m_mat1;
	MyVector3 m_vect[3];
	
	
	

	switch (t_axis)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
	
		break;
	default:
		break;
	}
}

void Game::translate(int t_val, char t_axis)
{
}

void Game::scale(int t_val)
{
}

