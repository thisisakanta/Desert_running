# include "iGraphics.h"

#define screenwidth 1000
#define screenheight 440

#define backgroundspeed 5

int counter=0;

int var;
int shootx=800,shooty=125;

int vanish=0;

int firex=200,firey=50;

int fire=0;
int point=0;
int sc[500];
char temp[200];
char temp2[200];
int norm=140;
int x = 3000, y = 0, o= 10,p=10,jd=0;

int r=255,g=255,b=255;
int q=250,t=245,w=80,m=40;
int h=290,k=325,ji=7;
int z=250,n=283,e=240,f=300;
int dx=10,dy=10;
char ami[30][39]= {"sh\\run1.bmp","sh\\run2.bmp","sh\\run3.bmp","sh\\run4.bmp","sh\\run5.bmp","sh\\Run6.bmp","sh\\run7.bmp","sh\\run8.bmp","sh\\run9.bmp","sh\\run10.bmp"};
char amio[40]="sh\\idle.bmp";
char anik[50][90]= {"sh\\jump0.bmp","sh\\jump1.bmp","sh\\jump2.bmp","sh\\jump3.bmp","sh\\jump4.bmp","sh\\jump5.bmp","sh\\jump6.bmp","sh\\jump7.bmp","sh\\jump8.bmp","sh\\jump9.bmp"};
int amix=200,amiy=0;
char slid[80]="sh//slide.bmp";
char last[80]="sh//dead.bmp";
char enemy[80][50]= {"part0.bmp","part2.bmp","part3.bmp"};
int enemyposition_x=1500,enemyposition_y=0;
int  po[200];

#define jumplimit 100

int yu=10,jo=180,mu=10,ko=220;
int index=0;
int standcounter=0;
int jump=0;
int  jumpup=0;
int down=0;
int ded=0;
int jumpco=0;
int width=70,height=60;
int xs=100,ys=130;
int first=0;

//homemenu

char button[4][20]= {"Menu\\1.bmp","Menu\\2.bmp","Menu\\3.bmp","Menu\\4.bmp"};
char homemenu[50]= {"Menu\\homemenu.bmp"};
char score[]= {};
char ins[20]= {};
int hj=0;
int lo=300;
int vb=0,te,i=0,j=0,bo=0;
int enemyindex=0;
int ni=0;
struct buttonCordinate
{
    int x;
    int y;

} bCordinate[4];


char backgroundimage[8][20]= {"1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp","8.bmp"};

struct background
{
    int x;
    int y;
};

background background[8];



/*
	function iDraw() is called again and again by the system.
*/

int gamestate=0;

void iDraw()
{
    //place your drawing codes here
    if(ni==0)
    {
        iShowBMP(0,0,"first.bmp");

        iSetColor(0,0,0);
        iText(380,220,"DESERT INFINTE RUNNING", GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,255);
        iText(380,0,"PRESS u TO GO TO THE MAIN GAME",GLUT_BITMAP_TIMES_ROMAN_24);



    }



    else
    {






        if(gamestate==0)
        {
            point=0;
            iShowBMP(0,0,"cha.bmp");
            for(int i=0; i<4; i++)
            {
                iShowBMP(bCordinate[i].x,bCordinate[i].y,button[i]);
            }

            iShowBMP2(650,20,"idle1.bmp",0);
            yu=10,jo=180,mu=10,ko=220;
            index=0;
            standcounter=0;
            jump=0;
            jumpup=0;
            down=0;
            ded=0;
            jumpco=0;
            width=70,height=60;
            xs=100,ys=130;
            x = 3000, y = 0, o= 10,p=10;
            counter=0;

            enemyposition_x=1500,enemyposition_y=0;



        }

        else if(gamestate==1 && point<223)
        {
            for(int i=0; i<8; i++)
            {
                iShowBMP(background[i].x,background[i].y,backgroundimage[i]);
            }

            iSetColor(0,0,0);
            iFilledRectangle(0, 0, 150, 440);
            iSetColor(255,255,255);

            iText(40, 350,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255,0,0);
            iText(35,40,"PAUSE[P]",GLUT_BITMAP_TIMES_ROMAN_24);



            if(jump)
            {
                if(jumpup)
                {

                    iShowBMP2(amix,amiy+jumpco,anik[5],0);
                }
                else
                    iShowBMP2(amix,amiy+jumpco,anik[8],0);
            }



            else if(down)
            {

                iShowBMP2(amix,amiy,slid,0);

            }


            else

                iShowBMP2(amix,amiy,ami[index],0);

            iSetColor(0,0,255);

            iFilledRectangle(x,y,width,height);
            iSetColor(255,255,255);

            iFilledRectangle(xs,ys,40,100);
            sprintf(temp, "%.5d", point);
            iSetColor(120, 220, 25);
            iText(40, 320, temp, GLUT_BITMAP_TIMES_ROMAN_24);

        }


        else if(gamestate==2)
        {
            iShowBMP(0,0,"scoring board.bmp");




            FILE *fp;
            fp=fopen("game.txt","r");
            hj=0;
            while(!feof(fp))
            {

                fscanf(fp,"%d",&sc[hj]);
                hj++;
            }

            fclose(fp);



            for(i=0; i<hj-1; i++)
            {
                for(j=i+1; j<hj; j++)
                {
                    if(sc[i]<sc[j])
                    {

                        te=sc[j];
                        sc[j]=sc[i];
                        sc[i]=te;
                    }
                }
            }

            iSetColor(0, 0, 0);
            iText(477,350,"BEST SCORE",GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(temp2,"%d",sc[0]);
            iText(480,300,"1.", GLUT_BITMAP_TIMES_ROMAN_24);

            iText(500,300,temp2, GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(temp2,"%d",sc[2]);
            iText(480,260,"2.", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,260, temp2, GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(temp2,"%d",sc[4]);
            iText(480,220,"3.", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,220, temp2, GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(temp2,"%d",sc[6]);
            iText(480,180,"4.", GLUT_BITMAP_TIMES_ROMAN_24);
            iText(500,180, temp2, GLUT_BITMAP_TIMES_ROMAN_24);
            iText(440,0,"PRESS b TO GO TO THE MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);


        }

        else if(gamestate==3)
        {
            iShowBMP(0,0,"instruction.bmp");
            iSetColor(255,255,255);
            iText(440,380,"1.PRESS d TO SLIDE",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(440,340,"2.PRESS SPACE TO JUMP",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(440,300,"3.PRESS f TO SHOOT THE ANIMAL",GLUT_BITMAP_TIMES_ROMAN_24);

            iShowBMP2(0,0,"idle1.bmp",0);

            iText(440,0,"PRESS b TO GO TO THE MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);






        }

        else if(gamestate==4)
            exit(0);






        else if(gamestate==5)
        {
            iShowBMP2(0,0,"background.bmp",255);

            iShowBMP2(400,150,"sh\\game.bmp",255);
            iShowBMP2(amix,amiy,last,0);

            iText(440,0,"PRESS b TO GO TO THE MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);






            sprintf(temp2,"%d",point);
            iSetColor(0,0,0);
            iText(40, 320, temp, GLUT_BITMAP_TIMES_ROMAN_24);

            yu=10,jo=180,mu=10,ko=220;
            index=0;
            standcounter=0;
            jump=0;
            jumpup=0;
            down=0;
            ded=0;
            jumpco=0;
            width=70,height=60;
            xs=100,ys=130;
            x = 3000, y = 0, o= 10,p=10;

            enemyposition_x=1500,enemyposition_y=0;

    if(counter==1)

{

 FILE *fp;
        fp=fopen("game.txt","a");

        fprintf(fp,"%d",point);
        fprintf(fp,"\n");


        fclose(fp);
  counter=0;
        }




        }

        else if(gamestate==1 && point>=220)
        {
            for(int i=0; i<8; i++)
            {
                iShowBMP(background[i].x,background[i].y,backgroundimage[i]);
            }

            iSetColor(0,0,0);
            iFilledRectangle(0, 0, 150, 440);
            iSetColor(255,255,255);

            iText(40, 350,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);

            iSetColor(255,0,0);
            iText(35,40,"PAUSE[P]",GLUT_BITMAP_TIMES_ROMAN_24);



            if(jump)
            {
                if(jumpup)
                {

                    iShowBMP2(amix,amiy+jumpco,anik[5],0);
                }
                else
                    iShowBMP2(amix,amiy+jumpco,anik[8],0);
            }



            else if(down)
            {

                iShowBMP2(amix,amiy,slid,0);

            }


            else
                iShowBMP2(amix,amiy,ami[index],0);


            iShowBMP2(enemyposition_x,enemyposition_y,enemy[enemyindex],255);


            if(fire)
            {
                iShowBMP2(firex,firey,"fire.bmp",0);
            }


            if(enemyposition_x==800)
            {
                var=1;
            }

            if(var)
            {

                iShowBMP2(shootx,shooty,"fire.bmp",0);
            }

            sprintf(temp, "%.5d", point);
            iSetColor(120, 220, 25);
            iText(40, 320, temp, GLUT_BITMAP_TIMES_ROMAN_24);


            if(firex>=enemyposition_x && firex<=enemyposition_x+40)
            {

                enemyposition_x=1500;
                firex=-100;
                fire=0;


            }




        }

        if(gamestate==6)

        {
            iShowBMP(0,0,"pause.bmp");
            iSetColor(255,0,0);
            iShowBMP2(0,0,"run.bmp",0);


            iText(460,200,"[o]",GLUT_BITMAP_TIMES_ROMAN_24);

            iText(500,200,"CONTINUE",GLUT_BITMAP_TIMES_ROMAN_24);
            iText(460,160,"[x]",GLUT_BITMAP_TIMES_ROMAN_24);

            iText(500,160,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);


            iText(460,120,"[e]",GLUT_BITMAP_TIMES_ROMAN_24);

            iText(500,120,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);






        }











    }


}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

        if(gamestate==0)
        {
            for(int i=0; i<4; i++)
            {
                if(mx>=bCordinate[i].x && mx<=bCordinate[i].x+150 && my>=bCordinate[i].y && my<=bCordinate[i].y+50)

                {
                    gamestate=i+1;
                }
            }

        }
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {

        index++;


        amix=300;

        if(index>=10)
            index=0;

    }
    if(key=='d')
    {
        PlaySound("slide.wav",NULL,SND_ASYNC);
        if(!down)
        {
            down=1;
        }
    }
    if(key==' ')
    {
        PlaySound("gruntjump.wav",NULL,SND_ASYNC);
        if(!jump)
        {
            jump=1;
            jumpup=1;
        }
    }

    if(key=='m')
    {
        if(gamestate==5 || gamestate==2 || gamestate==3 || gamestate==4)
            gamestate=0;
    }


    if(key=='b')
    {
        gamestate=0;
    }

    if(key=='f')
    {
        if(point>200)
        {
            fire=1;
            firex=300;
        }
    }
    if(key=='u')
    {
        ni=1;
        gamestate=0;

    }
    if(key=='p')
    {
        gamestate=6;







    }
    if(key=='o')
    {
        gamestate=1;







    }
    if(key=='x')
    {
        gamestate=0;







    }

    if(key=='e')
    {
        exit(0);







    }








    //place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }


    //place your codes for other keys here
}

void setall()
{
    int sum=0;
    for(int i=0; i<8; i++)
    {
        background[i].y=0;
        background[i].x=sum;
        sum=sum+125;
    }
}


void change1()
{

    for(int i=0; i<8; i++)
    {
        background[i].x=background[i].x-backgroundspeed;

        if( background[i].x<0)
            background[i].x=screenwidth;

    }
}

void change2()
{
    norm=140;

    if(jump)
    {

        if(jumpup)
        {
            jumpco+=10;
            if(jumpco>=jumplimit)
                jumpup=0;

        }

        else
        {
            jumpco-=10;
            if(jumpco<0)
            {
                jump=0;
                jumpco=0;
            }
        }
    }


    if(down)
    {
        norm=0;
        p--;
        amix++;


        if(p<-5)
        {
            index=0;
            down=0;
            p=10;
        }
    }


    index++;

    amix=200;

    if(index>=10)
        index=0;

    if(gamestate==1)
        point++;
}


void block()
{
    if(gamestate==1)
    {

        x-=10;
        if(x<150)
            x=2000;

        xs-=10;
        if(xs<150)
            xs=2000;

    }

}

void enemymove()
{
    if(gamestate==1)
    {

        if(point>200)
        {
            enemyposition_x-=20;
            if(enemyposition_x<150)
            {
                enemyposition_x=2000;
            }
        }

        enemyindex++;
        if(enemyindex>=3)
            enemyindex=0;
    }
}
void collision()
{

    if((((amix>=x && amix<=x+width) && (amiy+jumpco)<height)||(amix>=xs && amix<=xs+40 && amiy+jumpco+norm>130))&& point<200)
    {
        ded=1;
        gamestate=5;
        counter++;

        PlaySound("splat.wav",NULL,SND_ASYNC);

      /*  FILE *fp;
        fp=fopen("game.txt","a");

        fprintf(fp,"%d",point);
        fprintf(fp,"\n");


        fclose(fp);*/

    }

    else if(enemyposition_x==amix)
    {

        ded=1;
        gamestate=5;
        PlaySound("splat.wav",NULL,SND_ASYNC);
         counter++;


       /* FILE *fp;

        fp=fopen("game.txt","a");

        fprintf(fp,"%d",point);
        fprintf(fp,"\n");

        fclose(fp);*/

    }

    else if(amix<=shootx+20 && amix >=shootx+20 && amiy+jumpco+norm>130)

    {
        ded=1;
        gamestate=5;
        PlaySound("splat.wav",NULL,SND_ASYNC);
         counter++;



/*

        FILE *fp;

        fp=fopen("game.txt","a");

        fprintf(fp,"%d",point);
        fprintf(fp,"\n");

        fclose(fp);*/
    }

    /* if(firex>=enemyposition_x && firex<=enemyposition_x+40)
     {

     enemyposition_x=1500;
     firex=-100;
     fire=0;


     }
    */

}


void buttonf()
{
    int sum=100;
    for(int i=3; i>=0; i--)
    {
        bCordinate[i].x=100;
        bCordinate[i].y=sum;
        sum=sum+80;
    }
}


void firemove()
{
    if(fire)
    {
        firex+=5;
    }
    if(firex>1000)
    {
        firex=-100;
        fire=0;
    }

    if(var)
    {
        shootx-=10;

        if(shootx<150)
        {
            var=0;
            shootx=800;
        }
    }
}

int main()
{
    buttonf();
    setall();
    iSetTimer(15,change1);
    iSetTimer(40,change2);
    iSetTimer(15,block);
    iSetTimer(150,enemymove);
    iSetTimer(1,collision);
    iSetTimer(20,firemove);


    //place your own initialization codes here.
    iInitialize( screenwidth, screenheight, "running from ct!");
    return 0;
}
