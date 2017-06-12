#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
float xr=0,yr=0;int axis=3;
int clflag=0;
GLfloat theta[2];
int begin=0;
int i=0,j=0,i1=0;GLfloat r[13]={0},s[13]={0},t[13]={0},u[13]={0},v[13]={0},w[13]={0};
GLfloat ymv[13]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
GLfloat xmv[13]={0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
GLfloat vertices[13][3]={{1.2, -1.0, 0.3},{0.8, -1.0,0.4},{1.1, -1.0,0.1},{1.1, -1.0, -0.1},{0.9, -1.0,0.1},{0.8, -1.0, -0.2},{0.1, -1.0, -0.2},{0.8, -1.0, 0.1},{1.2, -1.0,-0.3},{0.2, -1.0,0.2},{0.1, -1.0,0.30},{0.3, -1.0,-0.2},{0.8, -1.0,0.6}};
GLfloat ammeter_color[2][4]={{0.90,0.0,0.0,0.0},{0.0,1.0,0.0,1.0}};
int start=0,start1=0,pause1=0,pause2=0;
char texta[]={"!!!PHOTO ELECTRIC EFFECT !!!"};
char textb[]={"(Computer Graphics Project)"};
char textc[]={"-Submitted by- "};
char textd[]={"ASHISH AGRAWAL"};
char texte[]={"1BI14CS032"};
char textf[]={"Department of Computer Science & Engineering"};
char textg[]={"Bangalore Institute of Technology"};
char texth[]={"***Press 'LEFT KEY' to Start***"};


void text(char str[],float x,float y,float z)
{
    int i;
    glRasterPos3f(x,y,z);
    for (i = 0; i <= strlen(str); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }   
}

void drawtext(float x,float y,char *s)
{
	int i;
	glRasterPos2f(x,y);
	for(i=0;s[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
}
void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)	axis=0;
	
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)	axis=1;
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)	axis=2;
 	
}		
void specialkey(int key,int x,int y)
{
 switch(key)
 {
  case GLUT_KEY_UP:yr-=0.05;
                   xr+=0.05;
    	               glutPostRedisplay();
	break;
case GLUT_KEY_LEFT:begin=1;
                
     break;   
  case GLUT_KEY_DOWN:yr+=0.05;
                   xr-=0.05;
	        /*for(i=0;i<13;i++)
		 {
		ymv[i]={0.0};
		xmv[i]={0.0};
		 }		
		r[13]={0},s[13]={0},t[13]={0},u[13]={0},v[13]={0},w[13]={0};*/
                   glutPostRedisplay();
                   
     break;	
 }
}	

void draw_circuit()
{
  glPushMatrix();//top plate
	glTranslated(0.7,1.0,0.0);
	glScaled(10.0,0.1,10.0);
	glutSolidCube(0.15);
	glPopMatrix(); 

	glPushMatrix();//bottom plate
	glTranslated(0.7,-1.0,0.0);
	glScaled(10.0,0.1,10.0);
	glutSolidCube(0.15);
	glPopMatrix();
        
	glBegin(GL_LINE_STRIP);
        glVertex3f(0.7,1.0,0.0);
        glVertex3f(0.7,1.5,0.0);
        glVertex3f(-1.2,1.5,0.0);
	glVertex3f(-1.2,-1.5,0.0);
	glVertex3f(0.7,-1.5,0.0);
	glVertex3f(0.7,-1.0,0.0);
	glEnd();
	
 
 glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[1]);
 drawtext(-2.2,-0.2,"Ammeter");
 drawtext(-1.3,0.3,"-");
 drawtext(1.0,1.4,"+");
 drawtext(-1.3,-0.4,"+");	
 drawtext(1.0,-1.4,"-");
}
void draw_text_a()
{
 GLfloat d2[]={1.0,1.0,1.0,0.0};
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
glDisable(GL_DEPTH_TEST);
glBegin(GL_POLYGON);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
        glVertex3f(-1.20,0.2,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
        glVertex3f(-1.30,-0.2,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
        glVertex3f(-1.25,-0.2,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
	glVertex3f(-1.25,-0.1,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
	glVertex3f(-1.15,-0.1,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
	glVertex3f(-1.15,-0.2,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,d2);
	glVertex3f(-1.10,-0.2,0.0);	
	glEnd();	
}
void draw_ammeter()
{
int i=12;
float x1=-1.2,y1=0.0,x2,y2;
float angle;
double radius=0.3;
	
if((ymv[i]>-0.2&&ymv[i]<0.2&&xmv[i]<=-1.2)||(ymv[i-1]>-0.2&&ymv[i-1]<0.2&&xmv[i-1]<=-1.2)||(ymv[i-2]>-0.2&&ymv[i-2]<0.2&&xmv[i-2]<=-1.2))

{
glBegin(GL_TRIANGLE_FAN);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[1]);
glVertex2f(x1,y1);
 
for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}
glEnd();
draw_text_a();
glBegin(GL_POLYGON);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[1]);
        glVertex3f(-1.22,-0.05,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[1]);
        glVertex3f(-1.18,-0.05,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[1]);
        glVertex3f(-1.20,0.13,0.0);

glEnd(); 


}
else
{
glBegin(GL_TRIANGLE_FAN);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[0]);
glVertex2f(x1,y1);
for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}
glEnd();
draw_text_a();
glBegin(GL_POLYGON);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[0]);
        glVertex3f(-1.22,-0.05,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[0]);
        glVertex3f(-1.18,-0.05,0.0);
glMaterialfv(GL_FRONT,GL_AMBIENT,ammeter_color[0]);
        glVertex3f(-1.20,0.13,0.0);
glEnd();
}

glutPostRedisplay();
}

void draw_lines()
{
   glBegin(GL_LINE_STRIP);
  glVertex3f(2.00-xr,0.00+yr,0.0);
  glVertex3f(1.80-xr, -0.05+yr,0.0);
  glVertex3f(1.90-xr, -0.10+yr,0.0);
  glVertex3f(1.70-xr, -0.15+yr,0.0);
  glVertex3f(1.80-xr, -0.20+yr,0.0);
  glVertex3f(1.60-xr, -0.25+yr,0.0);
  glVertex3f(1.70-xr, -0.30+yr,0.0);
  glVertex3f(1.50-xr, -0.35+yr,0.0);
  glVertex3f(1.60-xr, -0.40+yr,0.0);
  glVertex3f(1.40-xr, -0.45+yr,0.0);
  glVertex3f(1.50-xr, -0.50+yr,0.0);
  glVertex3f(1.30-xr, -0.56+yr,0.0);  
glEnd();

     glBegin(GL_LINE_STRIP);
      glVertex3f(2.00-xr,0.00+yr,-0.40);
  glVertex3f(1.80-xr, -0.05+yr,-0.40);
  glVertex3f(1.90-xr, -0.10+yr,-0.40);
  glVertex3f(1.70-xr, -0.15+yr,-0.40);
  glVertex3f(1.80-xr, -0.20+yr,-0.40);
  glVertex3f(1.60-xr, -0.25+yr,-0.40);
  glVertex3f(1.70-xr, -0.30+yr,-0.40);
  glVertex3f(1.50-xr, -0.35+yr,-0.40);
  glVertex3f(1.60-xr, -0.40+yr,-0.40);
  glVertex3f(1.40-xr, -0.45+yr,-0.40);
  glVertex3f(1.50-xr, -0.50+yr,-0.40);
  glVertex3f(1.30-xr, -0.56+yr,-0.40);  
glEnd();

    glBegin(GL_LINE_STRIP);
      glVertex3f(2.00-xr,0.00+yr,-0.20);
  glVertex3f(1.80-xr, -0.05+yr,-0.20);
  glVertex3f(1.90-xr, -0.10+yr,-0.20);
  glVertex3f(1.70-xr, -0.15+yr,-0.20);
  glVertex3f(1.80-xr, -0.20+yr,-0.20);
  glVertex3f(1.60-xr, -0.25+yr,-0.20);
  glVertex3f(1.70-xr, -0.30+yr,-0.20);
  glVertex3f(1.50-xr, -0.35+yr,-0.20);
  glVertex3f(1.60-xr, -0.40+yr,-0.20);
  glVertex3f(1.40-xr, -0.45+yr,-0.20);
  glVertex3f(1.50-xr, -0.50+yr,-0.20);
  glVertex3f(1.30-xr, -0.56+yr,-0.20);  
glEnd();
GLfloat d3[]={0.0,0.0,1.0,1.0};
	glBegin(GL_TRIANGLES);
glMaterialfv(GL_FRONT,GL_AMBIENT,d3);
        glVertex3f(1.33-xr, -0.60+yr, 0);
        glVertex3f(1.29-xr, -0.50+yr, 0);
        glVertex3f(1.27-xr, -0.60+yr, 0);
        glEnd();
  	glBegin(GL_TRIANGLES);
glMaterialfv(GL_FRONT,GL_AMBIENT,d3);
        glVertex3f(1.33-xr, -0.60+yr, -0.20);
        glVertex3f(1.29-xr, -0.50+yr, -0.20);
        glVertex3f(1.27-xr, -0.60+yr, -0.20);
        glEnd();
	glBegin(GL_TRIANGLES);
glMaterialfv(GL_FRONT,GL_AMBIENT,d3);
        glVertex3f(1.33-xr, -0.60+yr, -0.40);
        glVertex3f(1.29-xr, -0.50+yr, -0.40);
        glVertex3f(1.27-xr, -0.60+yr, -0.40);
        glEnd();
   
}
void other_elec()
{


       	glPushMatrix();
	glTranslatef(vertices[0][0],vertices[0][1],vertices[0][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
        
        glPushMatrix();
	glTranslatef(vertices[1][0],vertices[1][1],vertices[1][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(vertices[2][0],vertices[2][1],vertices[2][2]);
	glutSolidSphere(0.03, 50, 50);
    	glPopMatrix();

         
        glPushMatrix();
	glTranslatef(vertices[3][0],vertices[3][1],vertices[3][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();	  

        glPushMatrix();
	glTranslatef(vertices[4][0],vertices[4][1],vertices[4][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();

        glPushMatrix();
	glTranslatef(vertices[5][0],vertices[5][1],vertices[5][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
         
        glPushMatrix();
	glTranslatef(vertices[6][0],vertices[6][1],vertices[6][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
   
          
 	glPushMatrix();
	glTranslatef(vertices[7][0],vertices[7][1],vertices[7][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();

        glPushMatrix();
	glTranslatef(vertices[8][0],vertices[8][1],vertices[8][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();  


        glPushMatrix();
	glTranslatef(vertices[9][0],vertices[9][1],vertices[9][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();

/*	glPushMatrix();
	glTranslatef(vertices[10][0],vertices[10][1],vertices[10][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();*/

/*glPushMatrix();
	glTranslatef(vertices[11][0],vertices[11][1],vertices[11][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();  */  


}

void draw_elec()
{

        glPushMatrix();
	glTranslatef(vertices[12][0],vertices[12][1],vertices[12][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
    }    
void draw_elec1()
{

        glPushMatrix();
	glTranslatef(vertices[11][0],vertices[11][1],vertices[11][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
    }
void draw_elec2()
{

        glPushMatrix();
	glTranslatef(vertices[10][0],vertices[10][1],vertices[10][2]);
	glutSolidSphere(0.03, 50, 50);
	glPopMatrix();
    }
void move_top_left(GLfloat *x,GLfloat ver,GLfloat *t)
{
 	*x=0.7-*t;	
          glPushMatrix();
	glTranslatef(*x,ver, 0.0);
	glutSolidSphere(0.03, 50, 50);
	
	
             glPopMatrix();
        glutPostRedisplay();
}
void move_top_bot(GLfloat *y,GLfloat ver,GLfloat *u)
{
          *y=1.5-*u;
 	glPushMatrix();
	glTranslatef(ver,*y, 0.0);
	glutSolidSphere(0.03, 50, 50);
            glPopMatrix();
        glutPostRedisplay();
}
void move_bot_right(GLfloat *x,GLfloat ver,GLfloat *v)
{
 	*x=-1.2+*v;	
        glPushMatrix();
	glTranslatef(*x,ver, 0.0);
	glutSolidSphere(0.03, 50, 50);
             glPopMatrix();
        glutPostRedisplay();
}
void move_bot_top(GLfloat *y,GLfloat ver,GLfloat *w)
{
  
	*y=-1.5+*w;	
         glPushMatrix();
	glTranslatef(ver,*y, 0.0);
	glutSolidSphere(0.03, 50, 50);
             glPopMatrix();
        glutPostRedisplay();
	
}
void move_top_top(GLfloat *y,GLfloat ver,GLfloat *s)
{
 	*y=-0.35+*s;	
         glPushMatrix();
	glTranslatef(ver,*y, 0.0);
	glutSolidSphere(0.03, 50, 50);
             glPopMatrix();
        glutPostRedisplay();
	
}
void move_betwn(GLfloat *y,GLfloat verx,GLfloat *s,GLfloat verz)
{
        *y=-1.0+*s;	
        glPushMatrix();
	glTranslatef(verx,*y,verz);
	//glRotatef(theta[0],0.0,1.0,0.0);
	//glTranslatef(-verx,-*y,-verz);
	glutSolidSphere(0.03, 50, 50);
            glPopMatrix();
	//theta[0]+=1.0;
        glutPostRedisplay(); 
}

void move_elec(int i)
{
 	
	
        if(ymv[i]>1.0 && ymv[i]<=1.5&&xmv[i]==0)
         {
	  GLfloat vert=0.7;
	 move_top_top(&ymv[i],vert,&s[i]);s[i]+=0.04;
         }
       else if(ymv[i]>1.5&&xmv[i]>=-1.2)
         {
          move_top_left(&xmv[i],1.5,&t[i]);t[i]+=0.04;
          
         }
	else if(xmv[i]<-1.2&&ymv[i]>=-1.5)
	{
	GLfloat vert=-1.2;
	 move_top_bot(&ymv[i],vert,&u[i]);u[i]+=0.04;
	}
	else if(ymv[i]<-1.5&&xmv[i]<=0.7)
         {
          GLfloat vert=-1.5;	
          move_bot_right(&xmv[i],vert,&v[i]);v[i]+=0.04;
         }
	
	else if(xmv[i]>0.7&&ymv[i]<-1.0)
         {
	  s[i]=0;t[i]=0;u[i]=0;v[i]=0;
	  GLfloat vert=0.7;
          move_bot_top(&ymv[i],vert,&w[i]);w[i]+=0.04;
	 }	
	
	else
	 {
	   
	   w[i]=0;xmv[i]=0;	
	  GLfloat verx=vertices[i][0];
	  GLfloat verz=vertices[i][2];	
 	  move_betwn(&ymv[i],verx,&s[i],verz);s[i]+=0.04;
     	 }
	
	 if(ymv[i]>1.0 &&ymv[i-1]<1.1&&start==0)
         {
	  xmv[i-1]=0;w[i-1]=0;
          GLfloat verx=vertices[i-1][0];
	  GLfloat verz=vertices[i-1][2];	
 	  move_betwn(&ymv[i-1],verx,&s[i-1],verz);s[i-1]+=0.04;
	  pause1=0;
         }
	else if(ymv[i]>-1.5 &&ymv[i-1]<1.5&&ymv[i-1]>=1.1&&pause1==0)
         {
	start=1;
	   GLfloat vert=0.7;
	 move_top_top(&ymv[i-1],vert,&s[i-1]);s[i-1]+=0.04;
          
         }
	else if(ymv[i-1]>=1.5&&xmv[i-1]>=-1.2)
         {
	  pause1=1;
          GLfloat vert=1.5;
	  move_top_left(&xmv[i-1],vert,&t[i-1]);t[i-1]+=0.04;
          
         }
	else if(ymv[i-1]>=-1.5&&xmv[i-1]<-1.2)
	{
	GLfloat vert=-1.2;
	 move_top_bot(&ymv[i-1],vert,&u[i-1]);u[i-1]+=0.04;
	}
	else if(ymv[i-1]<-1.5&&xmv[i-1]<=0.7)
         {
	  GLfloat vert=-1.5;	
          move_bot_right(&xmv[i-1],vert,&v[i-1]);v[i-1]+=0.04;
         }
	else if(xmv[i-1]>0.7&&ymv[i-1]<-1.0)
	{
  	s[i-1]=0;t[i-1]=0;u[i-1]=0;v[i-1]=0;
	GLfloat vert=0.7;
          move_bot_top(&ymv[i-1],vert,&w[i-1]);w[i-1]+=0.04;
	}
	else
	 start=0;
	
	if(ymv[i-1]>1.0 &&ymv[i-2]<1.1&&start1==0)
         {
	  xmv[i-2]=0;w[i-2]=0;
          GLfloat verx=vertices[i-2][0];
	  GLfloat verz=vertices[i-2][2];	
 	  move_betwn(&ymv[i-2],verx,&s[i-2],verz);s[i-2]+=0.04;
	     pause2=0;       
         }
	else if(ymv[i-1]>-1.5 &&ymv[i-2]<1.5&&ymv[i-2]>=1.1&&pause2==0)
         {
	start1=1;
	  
          GLfloat vert=0.7;
	 move_top_top(&ymv[i-2],vert,&s[i-2]);s[i-2]+=0.04;
          
         }
	else if(ymv[i-2]>=1.5&&xmv[i-2]>=-1.2)
         {
	pause2=1;
          GLfloat vert=1.5;
	  move_top_left(&xmv[i-2],vert,&t[i-2]);t[i-2]+=0.04;
          
         }
	else if(ymv[i-2]>=-1.5&&xmv[i-2]<-1.2)
	{
	GLfloat vert=-1.2;
	 move_top_bot(&ymv[i-2],vert,&u[i-2]);u[i-2]+=0.04;
	}
	else if(ymv[i-2]<-1.5&&xmv[i-2]<=0.7)
         {
	  GLfloat vert=-1.5;	
          move_bot_right(&xmv[i-2],vert,&v[i-2]);v[i-2]+=0.04;
         }
	else if(xmv[i-2]>0.7&&ymv[i-2]<-1.0)
	{
  	s[i-2]=0;t[i-2]=0;u[i-2]=0;v[i-2]=0;
	GLfloat vert=0.7;
          move_bot_top(&ymv[i-2],vert,&w[i-2]);w[i-2]+=0.04;
	}
	else
	 start1=0;

}

void displaySolid(void)
{
	double winht;
	GLfloat mat_ambient[]={0.0,0.0,1.0,1.0};
	GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
	GLfloat mat_specular[]={1.0,0.0,0.0,1.0};
	GLfloat mat_shininess[]={50.0};
	
	GLfloat lightintensity[]={0.7,0.7,0.7,1.0};
	GLfloat lightposition[]={2.0,6.0,3.0,0.0};

	glMaterialfv(GL_FRONT,GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS, mat_shininess);

	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightintensity);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);

//	glRotatef(theta[1],0.0,1.0,0.0);
	
	glLoadIdentity();
	gluLookAt(2.0,1.0,2.0,0.0,0.2,0.2,0.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

if(begin!=0)
	{
		

		if(clflag==0)
		glClearColor(0.96,0.7,0.26,1.0);
		else
		glClearColor(1.0,1.0,1.0,1.0);
		
if(axis<=2);
{
glRotatef(theta[0],1.0,0.0,0.0); 
glRotatef(theta[1],0.0,1.0,0.0);
glRotatef(theta[2],0.0,0.0,1.0);
 theta[axis]+=1.0;
if(theta[axis]>360.0)
 theta[axis]-=360.0;
}
draw_lines();
 draw_circuit();
  i1=12; 	
 draw_ammeter();
 glEnable(GL_DEPTH_TEST);
 i1=12;
 if(ymv[i1-1]==0.0&&vertices[i1-1][0]==-1.0)
  draw_elec1();
  if(ymv[i1-2]==0.0&&vertices[i1-2][1]==-1.0)
  draw_elec2();      
    if(ymv[i1]==0.0&&vertices[i1][1]==-1.0)
  draw_elec();     
 if(xr>=0.30||yr<=-0.35)
  {
   move_elec(i1);
   xr=0.30;
   yr=-0.35;  
  }

 other_elec();
}
    else{
        //printing details
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glColor3f(1.0, 1.0, 1.0);
        text(texta, -2.0, 1.600,0);
        text(textb, -2.0, 1.200,0);
        text(textc, -2.0, 0.8,0);
        text(textd, -2.0, 0.40,0);
        text(texte, -2.0, 0.05,0);
        text(textf, -2.0, -0.45,0);
        text(textg, -2.0, -0.75,0);
        text(texth, -2.0, -1.0,0);
        glutPostRedisplay();
    	
       }

glFlush();
glutSwapBuffers();
}
void start_ray()
{
 for(xr=0;xr<0.30;xr+=0.05)
 {
   if(yr>-0.35)
   yr-=0.05;
  glutPostRedisplay();	
 }

    	
}
void stop_ray()
{
 xr=0.0,yr=0.0;
 glutPostRedisplay();
}
void menu(int d)
{
	switch(d)
	{
		case 1:start_ray();
				
			break;
		case 2: axis=0;
			break;
		case 3: axis=1;
			break;
		case 4:axis=2;
			break;
		case 5: clflag=1;
			break;
		case 6:exit(0);
		case 7:stop_ray();
			theta[0]=0.0;
			theta[1]=0.0;
			theta[2]=0.0;
	        case 8: axis=3;
 			break; 
		}
	glFlush();
	glutPostRedisplay();
	
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(500,500);
	glutCreateWindow("Photoelectric effect");
	glutDisplayFunc(displaySolid);
	glutSpecialFunc(specialkey);
	glutCreateMenu(menu);
	glutAddMenuEntry("Start",1);
	glutAddMenuEntry("Rotate x",2);
	glutAddMenuEntry("Rotate y",3);
	glutAddMenuEntry("Rotate z",4);
	glutAddMenuEntry("Stop Rotation",8);
	glutAddMenuEntry("CHANGE COLOR",5);
	glutAddMenuEntry("Exit",6);
	glutAddMenuEntry("Reset",7);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMouseFunc(mouse);
	//glutIdleFunc(spincirc);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
		
	glEnable(GL_NORMALIZE);
	
	
	glutMainLoop();
}
