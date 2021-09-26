#include "Helpers.h"

void runMainLoop(int val);

int main( int argc, char* args[] ){

	glutInit( &argc, args );

    GLint WindowID1, WindowID2;
	glutInitDisplayMode( GLUT_SINGLE|GLUT_RGB );
	glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	
    WindowID1 = glutCreateWindow( "Window");
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    
	cout<<"Enter window dimensions: "<<endl;
	cout<<"Enter minimum X value: "; cin>>window_x_dims.first;
	cout<<"Enter maximum X value: "; cin>>window_x_dims.second;
	cout<<"Enter minimum Y value: "; cin>>window_y_dims.first;
	cout<<"Enter maximum Y value: "; cin>>window_y_dims.second;


	int option=0;
	cout<<"Choose number of edges: (1 for line, 3 and upwards for polygon): ";
	cin>>option;

	setEdgeCount(option);
	cout<<"Enter vertices: "<<endl;
	for(int i=0;i<edge_count;i++){
		cout<<"Vertex "<<i+1<<" (x,y): ";
		double x,y;
		cin>>x>>y;
		original_points.push_back(pair<double, double>(x, y));
	}

	drawWindowFigure();


	cout<<"Enter viewport dimensions: "<<endl;
	cout<<"Enter minimum X value: "; cin>>viewport_x_dims.first;
	cout<<"Enter maximum X value: "; cin>>viewport_x_dims.second;
	cout<<"Enter minimum Y value: "; cin>>viewport_y_dims.first;
	cout<<"Enter maximum Y value: "; cin>>viewport_y_dims.second;


	if( !initGL() )
	{
		printf( "Unable to initialize graphics library!\n" );
		return 1;
	}

	glutDisplayFunc( renderOG);
    WindowID2 = glutCreateWindow( "Viewport");
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glutDisplayFunc(renderTrans);
    if( !initGL() )
    {
        printf( "Unable to initialize graphics library!\n" );
        return 1;
    }

    //	glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

	glutMainLoop();

	return 0;
}

void runMainLoop( int val ){
    update();
//    render();

    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
