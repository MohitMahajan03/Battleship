//randomize ships!
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>

class ship
{
	private:
		int x,y,t1,r1,t2,r2,t3,r3,t4,r4,i1,k1,i2,k,k2,i3,k3,i4,k4,c1,c2,c3,c4;
		int theta;
		int gun1_x,gun1_y,gun2_x,gun2_y,gun3_x,gun3_y,gun4_x,gun4_y;
		int spx1,spy1,spx2,spy2,spx3,spy3,spx4,spy4;
		float q1m1,q1m2,q2m1,q2m2,q3m1,q3m2,q4m1,q4m2,x1,y1,z1,x2,y2,z2,x3,y3,z3,x4,y4,z4;
		int j1,j2,j3,j4,flag,s,n1,n2,n3,n4,status[20],w;

	public:
		void gameboard();
		void quad_1_missile(int c1);
		void quad_2_missile(int c2);
		void quad_3_missile(int c3);
		void quad_4_missile(int c4);
		void missile_1_hit_or_miss(float x1, float y1, float z1, int s);
		void missile_2_hit_or_miss(float x2, float y2, float z2, int s);
		void missile_3_hit_or_miss(float x3, float y3, float z3, int s);
		void missile_4_hit_or_miss(float x4, float y4, float z4, int s);
		void reset_enemy_ships();
		void wicket(int s);
		void enemy_ship_left_toptobottom();
		void enemy_ship_right_toptobottom();
		void video();
		void tutorial();
		void level1();
		void input();
		void coord_calc(int theta,int &x,int &y);
		void fire_missile(int oldx, int oldy, int spx, int spy,int speed, int dist);

};

void ship :: gameboard()
{

	//aircraft carrier
	bar(319-4,239-85,319+4,239);
	//destroyer 3rd quadrant
	line(319-10,239-20,319-10,239+20);  // mid co-ordinates (x,y)
	line(319-10,239-20,319-20,239-30);
	line(319-20,239-30,319-30,239-20);
	line(319-30,239-20,319-30,239+20);
	line(319-30,239+20,319-20,239+30);
	line(319-20,239+30,319-10,239+20);
	//destroyer 4th quadrant
	line(319+10,239-20,319+10,239+20);
	line(319+30,239-20,319+30,239+20);
	line(319+10,239-20,319+20,239-30);
	line(319+30,239-20,319+20,239-30);
	line(319+10,239+20,319+20,239+30);
	line(319+30,239+20,319+20,239+30);
	//destroer 1st quadrant
	line(319-10,239-60,319-10,239-100);
	line(319-20,239-110,319-10,239-100);
	line(319-30,239-100,319-20,239-110);
	line(319-30,239-60,319-30,239-100);
	line(319-20,239-50,319-30,239-60);
	line(319-20,239-50,319-10,239-60);
	//destroyer 2nd quadrant
	line(319+10,239-60,319+10,239-100);
	line(319+30,239-60,319+30,239-100);
	line(319+10,239-60,319+20,239-50);
	line(319+30,239-60,319+20,239-50);
	line(319+10,239-100,319+20,239-110);
	line(319+30,239-100,319+20,239-110);
}

void ship :: reset_enemy_ships()
{
	for(w=0;w<20;w++)
	{
		status[w] = 0;
	}
}

void ship :: wicket(int s)
{
	for(w=0;w<20;w++)
	{
		if(w == s)
		{
			status[w] = 1;
		}
	}
}
// gives rsin(theta) and rcos(theta) for missile co-ordinates
void ship::coord_calc(int theta, int &x, int &y)
{
	x = 20*cos(theta*(3.14159/180));
	y = 20*sin(theta*(3.14159/180));

}

void ship::fire_missile(int theta, int spx, int spy, int speed, int dist)
{
	int newx, newy;
	int posx, posy;
	coord_calc(theta, newx, newy);
	posx = spx + newx;
	posy = spy - newy;
	setcolor(15);
	line(posx+(speed*dist),posy+(speed*dist))

}
void ship :: quad_1_missile(int c1)
{
	if(c1 != 370)
	{
		//1st quadrant missile co-ordinates
		q1m2 = c1;
		q1m1 = q1m2;
		q1m2 = cos(q1m2*(3.14159/180));
		q1m1 = sin(q1m1*(3.14159/180));
		t1 = 169 - (q1m1*20);
		r1 = 289 + (q1m2*20);

		setcolor(15);
		line(r1+(5*j1*q1m2),t1-(5*j1*q1m1),289+(5*j1*q1m2),169-(5*j1*q1m1)); //1st quadrant destroyer missiles

	}
	else
	{
		r1 = 0; t1 = 0;
	}
}

void ship :: quad_2_missile(int c2)
{

	if(c2 != 370)
	{
		//2nd quadrant missile co-ordinates
		q2m2 = c2;
		q2m1 = q2m2;
		q2m2 = cos(q2m2*(3.14159/180));
		q2m1 = sin(q2m1*(3.14159/180));
		t2 = 169 - (q2m1*20);
		r2 = 349 + (q2m2*20);

		setcolor(15);
		line(r2+(5*j2*q2m2),t2-(5*j2*q2m1),349+(5*j2*q2m2),169-(5*j2*q2m1)); //2nd quadrant destroyer missiles

	}
	else
	{
		r2 = 0;
		t2 = 0;
	}
}

void ship :: quad_3_missile(int c3)
{
	if(c3 != 370)
	{
		//3rd quadrant missile co-ordinates
		q3m2 = c3;
		q3m1 = q3m2;
		q3m2 = cos(q3m2*(3.14159/180));
		q3m1 = sin(q3m1*(3.14159/180));
		t3 = 239 - (q3m1*20);
		r3 = 289 + (q3m2*20);

		setcolor(15);
		line(r3+(5*j3*q3m2),t3-(5*j3*q3m1),289+(5*j3*q3m2),239-(5*j3*q3m1)); //3rd quadrant destroyer missiles
	}
	else
	{
		r3 = 0;
		t3 = 0;
	}
}

void ship :: quad_4_missile(int c4)
{

	if(c4 != 370)
	{
		//4th quadrant missile co-ordinates
		q4m2 = c4;
		q4m1 = q4m2;
		q4m2 = cos(q4m2*(3.14159/180));
		q4m1 = sin(q4m1*(3.14159/180));
		t4 = 239 - (q4m1*20);
		r4 = 349 + (q4m2*20);

		setcolor(15);
		line(r4+(5*j4*q4m2),t4-(5*j4*q4m1),349+(5*j4*q4m2),239-(5*j4*q4m1)); //3rd quadrant destroyer missiles
	}
	else
	{
		r4 = 0;
		t4 = 0;
	}

}

void ship :: missile_1_hit_or_miss(float x1, float y1, float z1, int s)
{
	if(c1 >= -90 && c1 <= 90)
	{
		if((r1+(5*j1*q1m2)) >= (x1-5) && (r1+(5*j1*q1m2)) <= (x1+5) && (t1-(5*j1*q1m1))<=y1 && (t1-(5*j1*q1m1))>=z1 && c1 != 370)
		{
			setcolor(14);
			for(i1=0;i1<70;i1++)
			{
				circle(r1+(5*j1*q1m2),t1-(5*j1*q1m1),i1);
				if(i1 == 40)
				cleardevice();
			}
			j1 = 0;
			c1 = 370;
			wicket(s);
			flag++;
		}
	}

	if((c1 >= 90 && c1 <= 180) || (c1 <= -90 && c1 >= -180))
	{
		 if((r1+(5*j1*q1m2)) >= (x1-5) && (r1+(5*j1*q1m2)) <= (x1+5) && (t1-(5*j1*q1m1))<=y1 && (t1-(5*j1*q1m1))>=z1 && c1 != 370)
		{
			setcolor(14);
			for(i1=0;i1<70;i1++)
			{
				circle(r1+(5*j1*q1m2),t1-(5*j1*q1m1),i1);
				if(i1 == 40)
				cleardevice();
			}
			j1 = 0;
			c1 = 370;
			wicket(s);
			flag++;
		}
	}

}

void ship :: missile_2_hit_or_miss(float x2, float y2, float z2, int s)
{
	if((c2 >= 90 && c2 <= 180) || (c2 <= -90 && c2 >= -180))
	{
		if((r2+(5*j2*q2m2))>=(x2-5) && (r2+(5*j2*q2m2))<=(x2+5) && (t2-(5*j2*q2m1))<=y2 && (t2-(5*j2*q2m1))>=z2 && c2 != 370)
		{
			setcolor(14);
			for(i2 = 0;i2 < 70;i2++)
			{
				circle((r2+(5*j2*q2m2)),(t2-(5*j2*q2m1)),i2);
				if(i2 == 40)
				cleardevice();

			}
			j2 = 0;
			wicket(s);
			c2 = 370;
			flag++;
		}
	}

	if(c2 >= -90 && c2 <= 90)
	{
		if((r2+(5*j2*q2m2)) >= (x2-5) && (r2+(5*j2*q2m2)) <= (x2+5) && (t2-(5*j2*q2m1))<=y2 && (t2-(5*j2*q2m1))>=z2 && c2 != 370)
		{
			setcolor(14);
			for(i2 = 0;i2 < 70;i2++)
			{
				circle((r2+(5*j2*q2m2)),(t2-(5*j2*q2m1)),i2);
				if(i2 == 40)
				cleardevice();

			}
			j2 = 0;
			wicket(s);
			c2 = 370;
			flag++;
		}
	}
}

void ship :: missile_3_hit_or_miss(float x3, float y3, float z3, int s)
{
	if((c3 >= 90 && c3 <= 180) || (c3 <= -90 && c3 >= -180))
	{
		if((r3+(5*j3*q3m2)) >= (x3-5) && (r3+(5*j3*q3m2)) <= (x3+5) && (t3-(5*j3*q3m1)) <= y3 && (t3-(5*j3*q3m1)) >= z3 && c3 != 370)
		{
			setcolor(14);
			for(i3=0;i3<70;i3++)
			{
				circle((r3+(5*j3*q3m2)),(t3-(5*j3*q3m1)),i3);
				if(i3 == 40)
				cleardevice();
				}
			j3 = 0;
			wicket(s);
			c3 = 370;
			flag++;
		}
	 }
	 if(c3 >= -90 && c3 <= 90)
	 {
		if((r3+(5*j3*q3m2)) >= (x3-5) && (r3+(5*j3*q3m2)) <= (x3+5) && (t3-(5*j3*q3m1)) <= y3 && (t3-(5*j3*q3m1)) >= z3 && c3 != 370)
		{
			setcolor(14);
			for(i3=0;i3<70;i3++)
			{
				circle((r3+(5*j3*q3m2)),(t3-(5*j3*q3m1)),i3);
				if(i3 == 40)
				cleardevice();
				}
			j3 = 0;
			wicket(s);
			c3 = 370;
			flag++;
		}
	 }

}

void ship :: missile_4_hit_or_miss(float x4, float y4, float z4, int s)
{

	if(c4 >= -90 && c4 <= 90)
	{
		if((r4+(5*j4*q4m2)) >= (x4-5) && (r4+(5*j4*q4m2)) <= (x4+5) && (t4-(5*j4*q4m1)) <= y4 && (t4-(5*j4*q4m1)) >= z4 && c4 != 370)
		{
			setcolor(14);
			for(i4=0;i4<70;i4++)
			{
				circle((r4+(5*j4*q4m2)),(t4-(5*j4*q4m1)),i4);
				if(i4 == 40)
				cleardevice();

			}
			j4 = 0;
			wicket(s);
			c4 = 370;
			flag++;

		}
	}

	if((c4 >= 90 && c4 <= 180) || (c4 <= -90 && c4 >= -180))
	{
		if((r4+(5*j4*q4m2)) >= (x4-5) && (r4+(5*j4*q4m2)) <= (x4+5) && (t4-(5*j4*q4m1)) <= y4 && (t4-(5*j4*q4m1)) >= z4 && c4 != 370)
		{
			setcolor(14);
			for(i4=0;i4<70;i4++)
			{
				circle((r4+(5*j4*q4m2)),(t4-(5*j4*q4m1)),i4);
				if(i4 == 40)
				cleardevice();

			}
			j4 = 0;
			wicket(s);
			c4 = 370;
			flag++;

		}
	}

}

void ship :: enemy_ship_left_toptobottom()
{
	setcolor(4);
	line(160,0+(2*n1),160,40+(2*n1));
	line(160,0+(2*n1),170,-10+(2*n1));
	line(180,0+(2*n1),170,-10+(2*n1));
	line(180,0+(2*n1),180,40+(2*n1));
	line(160,40+(2*n1),170,50+(2*n1));
	line(180,40+(2*n1),170,50+(2*n1));
}

void ship :: enemy_ship_right_toptobottom()
{
	setcolor(4);
	line(460,0+(2*n2),460,40+(2*n2));
	line(460,0+(2*n2),470,-10+(2*n2));
	line(480,0+(2*n2),470,-10+(2*n2));
	line(480,0+(2*n2),480,40+(2*n2));
	line(460,40+(2*n2),470,50+(2*n2));
	line(480,40+(2*n2),470,50+(2*n2));

}

void ship :: input()
{
	cout<<"Enter the ship number and angle"<<endl;
	cin>>k;
	switch(k)
	{
		case 1: cin>>c1;
			j1 = 0;
			break;

		case 2: cin>>c2;
			j2 = 0;
			break;

		case 3: cin>>c3;
			j3 = 0;
			break;

		case 4: cin>>c4;
			j4 = 0;
			break;

		default: getch();
	}


}

void ship :: video()
{

	i1 = 0;k1 = 0;i2 = 0;k2 = 0;i3 = 0;k3 = 0;i4 = 0;k4 = 0;
	j1 = 0;j2 = 0;j3 = 0;j4 = 0;
	for(x=0;x<50;x++)
	{
		cout<<"\n\n\n\n\n"<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		cout<<" PIRATES OF THE INDIAN OCEAN \t\t\t\t\t LOADING..."<<endl;

		for(y=0;y<50;y++)
		{

			setcolor(2);
			gameboard();

			//1st quadrant shooting
			if((r1+(5*j1*q1m2))<=180 && (t1-(5*j1*q1m1))<=130 && (t1-(5*j1*q1m1)>=80) && i1<70)
			{
				setcolor(14);
				circle((r1+(5*j1*q1m2)),(t1-(5*j1*q1m1)),i1);
				i1 = i1+1;
				k1 = 1;
			}

			else if(k1 == 0)
			{
				//enemy ship 1st quandrant
				setcolor(4);
				line(160,80,160,120);
				line(160,80,170,70);
				line(180,80,170,70);
				line(180,80,180,120);
				line(160,120,170,130);
				line(180,120,170,130);

				setcolor(15);
				quad_1_missile(145);
			       //	line(r1-(5*x*q1m2),t1-(5*x*q1m1),289-(5*x*q1m2),169-(5*x*q1m1)); //1st quadrant destroyer missiles
			}

			// 3rd quadrant shooting


			if(r3+(5*j3*q3m2)<=209 && t3-(5*j3*q3m1)<=369 && t3-(5*j3*q3m1)>=309 && i3<70)
			{
				setcolor(14);
				circle((r3+(5*j3*q3m2)),(t3-(5*j3*q3m1)),i3);
				i3 = i3+1;
				k3 = 1;
			}
			else if(k3==0)
			{
				//3rd quadrant enemy ship
				setcolor(4);
				line(319-110,239+80,319-110,239+120);
				line(319-110,239+80,319-120,239+70);
				line(319-120,239+70,319-130,239+80);
				line(319-130,239+80,319-130,239+120);
				line(319-130,239+120,319-120,239+130);
				line(319-120,239+130,319-110,239+120);

				setcolor(15);
				quad_3_missile(-135);
				//line(r3-(5*x*q3m2),t3+(5*x*q3m1),289-(5*x*q3m2),239+(5*x*q3m1)); //3rd quadrant destroyer missiles
			}

			//2nd quadrant shooting
			if(r2+(5*j2*q2m2)>=429 && t2+(5*j2*q2m1)>=129 && t2+(5*j2*q2m1)<=189 && i2<70)
			{
				setcolor(14);
				circle((r2+(5*j2*q2m2)),(t2+(5*j2*q2m1)),i2);
				i2 = i2+1;
				k2 = 1;

			}
			else if(k2 == 0)
			{
				//2nd quadrant enemy ship
				setcolor(4);
				line(319+110,239-60,319+110,239-100);
				line(319+130,239-60,319+130,239-100);
				line(319+110,239-60,319+120,239-50);
				line(319+130,239-60,319+120,239-50);
				line(319+110,239-100,319+120,239-110);
				line(319+130,239-100,319+120,239-110);

				setcolor(15);
				quad_2_missile(15);
			}

			//4th quadrant shooting
			if(r4+(5*j4*q4m2) >= 419 && t4-(5*j4*q4m1) <= 289 && t4-(5*j4*q4m1) >= 239 && i4<70)
			{
				setcolor(14);
				circle((r4+(5*j4*q4m2)),(t4-(5*j4*q4m1)),i4);
				i4 = i4+1;
				k4 = 1;

			}

			else if(k4 == 0)
			{
				//4th quadrant enemy ship
				setcolor(4);
				line(319+100,239-0,319+100,239+40);
				line(319+120,239-0,319+120,239+40);
				line(319+100,239-0,319+110,239-10);
				line(319+120,239-0,319+110,239-10);
				line(319+100,239+40,319+110,239+50);
				line(319+120,239+40,319+110,239+50);

				setcolor(15);
				quad_4_missile(-15);

			}
		}
		cleardevice();
		j1++; j2++; j3++; j4++;
	}
}

void ship :: level1()
{
	int x,y,jr1;
	c1 = 370; c2 = 370; c3 = 370; c4 = 370;
	n1 = -20; n2 = -100;
	reset_enemy_ships();
	flag = 0;
	cout<<"LEVEL 1"<<endl;
	getch();
	while ( flag < 2)
	{
		for(y=0;y<100;y++)
		{

			setcolor(2);
			gameboard();

			quad_1_missile(c1);
			quad_2_missile(c2);
			quad_3_missile(c3);
			quad_4_missile(c4);


			if(status[1] == 0)
			{
				enemy_ship_left_toptobottom();

				x1 = x2 = x3 = x4 = 180;
				y1 = y2 = y3 = y4 = 50+(2*n1);
				z1 = z2 = z3 = z4 = 0+(2*n1);
				s = 1;

			}
				missile_1_hit_or_miss(x1, y1, z1, s);
				missile_2_hit_or_miss(x2, y2, z2, s);
				missile_3_hit_or_miss(x3, y3, z3, s);
				missile_4_hit_or_miss(x4, y4, z4, s);


			if(status[2] == 0)
			{
				enemy_ship_right_toptobottom();



				x1 = x2 = x3 = x4 = 460;
				y1 = y2 = y3 = y4 = 50+(2*n2);
				z1 = z2 = z3 = z4 = 0+(2*n2);
				s = 2;

			}

				missile_1_hit_or_miss(x1, y1, z1, s);
				missile_2_hit_or_miss(x2, y2, z2, s);
				missile_3_hit_or_miss(x3, y3, z3, s);
				missile_4_hit_or_miss(x4, y4, z4, s);


		}

		if((x+1) % 50 == 0)
		{
			input();
		}
		j1++; j2++; j3++; j4++;
		n1++; x++; n2++;
		if(flag > 1)
		{
			cout<<"YOU WIN!"<<endl;
			getch();
			break;
		}
		cleardevice();

	}
	reset_enemy_ships();
}

void main()
{
	clrscr();
	int gdriver=DETECT,gm,j;
	initgraph(&gdriver, &gm, "c:/turboc3/bgi");
	ship s;
	s.video();
	s.level1();
	getch();
}

/*
				Documentation


	1. List of User defined Functions

	1.1

*/