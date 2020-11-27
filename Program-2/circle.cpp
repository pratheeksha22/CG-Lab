#include<gl/glut.h>
#include<stdio.h>
int xc, yc, r;

void draw_circle(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);

	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - y, yc - x);
	glEnd();
}

void circlebres()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int x = 0, y = r;
	int d = 3 - 2 * r;
	while (x <= y)
	{
		draw_circle(xc, yc, x, y);
		x++;
		if (d < 0)
			d = d + 4 * x + 6;

		else
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		draw_circle(xc, yc, x, y);
	}
	glFlush();
}

void minit()
{
	glClearColor(1, 1, 1, 1);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	gluOrtho2D(10, 500, 10, 500);
}


int main(int argc, char* argv[])
{
	printf_s("Enter the radius:");
	scanf_s("%d", &r);
	printf_s("Enter the co-ordinates:\nx1=");
	scanf_s("%d", &xc);
	printf_s("y1=");
	scanf_s("%d", &yc);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(5, 5);
	glutCreateWindow("Bresenhamís circle drawing.");
	glutDisplayFunc(circlebres);
	minit();
	glutMainLoop();
	return 0;
}

