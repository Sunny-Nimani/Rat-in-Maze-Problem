// CPP program to solve Rat in a maze
// problem with backtracking using stack

#include <cstring>
#include <iostream>
#include <stack>
#include<stdio.h>
//#include<dos.h>
#include<graphics.h>
#include<conio.h>


using namespace std;

#define N 5
#define M 5

class node {
public:
    int x, y;
    int dir;

    node(int i, int j)
    {
        x = i;
        y = j;

        // Initially direction
        // set to 0
        dir = 0;
    }
};

// maze of n*m matrix
int n = N, m = M;
  int solution[N][M];
// Coordinates of food
int fx, fy;
bool visited[N][M];


void boundaryfill(int x,int y,int f_color,int b_color)
{
	if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
	{
		putpixel(x,y,f_color);
		boundaryfill(x+1,y,f_color,b_color);
		boundaryfill(x,y+1,f_color,b_color);
		boundaryfill(x-1,y,f_color,b_color);
		boundaryfill(x,y-1,f_color,b_color);
		boundaryfill(x+1,y-1,f_color,b_color);
		boundaryfill(x-1,y+1,f_color,b_color);
		boundaryfill(x-1,y-1,f_color,b_color);
		boundaryfill(x+1,y+1,f_color,b_color);

	}
}

bool isReachable(int maze[N][M])
{
    // Initially starting at (0, 0).
    int i = 0, j = 0;

    stack<node> s;

    node temp(i, j);

    s.push(temp);

    while (!s.empty()) {

        // Pop the top node and move to the
        // left, right, top, down or retract
        // back according the value of node's
        // dir variable.
        temp = s.top();
        int d = temp.dir;
        i = temp.x, j = temp.y;

        // Increment the direction and
        // push the node in the stack again.
        temp.dir++;
        s.pop();
        s.push(temp);

        // If we reach the Food coordinates
        // return true
        if (i == fx and j == fy) {
                solution[i][j]=1;
            return true;

      }

        // Checking the Up direction.
        if (d == 0) {
            if (i - 1 >= 0 and maze[i - 1][j] and
                                    visited[i - 1][j]) {
                node temp1(i - 1, j);       //create node type variable
solution[i][j]=1;
	visited[i - 1][j] = false; //mark in solution array
                s.push(temp1);

	}
        }

        // Checking the left direction
        else if (d == 1) {
            if (j - 1 >= 0 and maze[i][j - 1] and
                                    visited[i][j - 1]) {
	      solution[i][j]=1;
                node temp1(i, j - 1);
                visited[i][j - 1] = false;
                s.push(temp1);
            }
        }

        // Checking the down direction
        else if (d == 2) {
            if (i + 1 < n and maze[i + 1][j] and
                                    visited[i + 1][j]) {
                node temp1(i + 1, j);
solution[i][j]=1;
visited[i + 1][j] = false;
                s.push(temp1);
            }
        }
        // Checking the right direction
        else if (d == 3) {
            if (j + 1 < m and maze[i][j + 1] and
                                    visited[i][j + 1]) {
solution[i][j]=1;
                node temp1(i, j + 1);
                visited[i][j + 1] = false;
                s.push(temp1);
            }
        }

        // If none of the direction can take
        // the rat to the Food, retract back
        // to the path where the rat came from.
        else {
	//  solution[i][j]=0;
            visited[temp.x][temp.y] = true;
            s.pop();
        }
    }

    // If the stack is empty and
    // no path is found return false.
    return false;
}






// Driver code
int main()
{
    // Initially setting the visited
    // array to true (unvisited)
    memset(visited, true, sizeof(visited));

for(int i=0;i<N;i++)
{
for(int j=0;j<M;j++)
{

	solution[i][j]=0;

}

}


      int  maze[N][M];
      cout<<"\nEnter maze elements\n";

for(int i=0;i<N;i++)
{
for(int j=0;j<M;j++)
{

	cin>>maze[i][j];

}

}


int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);



   /* // Maze matrix
    int  maze[N][M] = {
        { 1, 0, 0, 1, 1 },
        { 1, 0, 1, 0, 1 },
        { 1, 0, 1, 0, 1 },
        { 1, 1, 1, 0, 1 },
        { 0, 0, 0, 0, 1 }
    };
*/
    // Food coordinates
    fx = 4;
    fy = 4;

    if (isReachable(maze)) {
        cout << "Path Found!" << '\n';


    }
    else
{
        cout << "No Path Found!" << '\n';
        outtextxy(260,260,"DESTINATION NOT REACHED");

}




for(int i=0;i<N;i++)
{
for(int j=0;j<M;j++)
{

	cout<<solution[i][j];
	cout<<"\t";
}
cout<<"\n";
}






//DRAW
outtextxy(3,70,"SOURCE->");
outtextxy(222,205,"<-DESTINATION");

	    line(70,70,220,70);
	    line(70,70,70,220);
	    line(220,70,220,220);
	    line(70,220,220,220);

int n=5;
int nn=5;
int gap=30;
while(n!=0)
{
line(70,70+gap,220,70+gap);
gap=gap+30;
n--;
}
int g=30;

while(nn!=0)
{
line(70+g,70,70+g,220);
g=g+30;
nn--;
}


if(solution[0][0]==1)
{
boundaryfill(71,71,10,15);
}
else
{
boundaryfill(71,71,4,15);
}
if(solution[0][1]==1)
{
boundaryfill(103,71,10,15);
}
else
{
boundaryfill(103,71,4,15);
}
if(solution[0][2]==1)
{
boundaryfill(153,71,10,15);

}
else
{
boundaryfill(153,71,4,15);
}
if(solution[0][3]==1)
{
boundaryfill(183,71,10,15);

}
else
{
boundaryfill(183,71,4,15);
}
if(solution[0][4]==1)
{
boundaryfill(218,71,10,15);

}
else
{
boundaryfill(218,71,4,15);
}
////////////////////////////////////////////////////////
if(solution[1][0]==1)
{
boundaryfill(71,111,10,15);

}
else
{
boundaryfill(71,111,4,15);
}
if(solution[1][1]==1)
{
boundaryfill(111,111,10,15);

}
else
{
boundaryfill(111,111,4,15);
}

if(solution[1][2]==1)
{
boundaryfill(153,111,10,15);

}
else
{
boundaryfill(153,111,4,15);
}
if(solution[1][3]==1)
{
boundaryfill(183,111,10,15);

}
else
{
boundaryfill(183,111,4,15);
}
if(solution[1][4]==1)
{
boundaryfill(218,111,10,15);

}
else
{
boundaryfill(218,111,4,15);
}
//////////////////////////////////////////////////
if(solution[2][0]==1)
{
boundaryfill(71,153,10,15);

}
else
{
boundaryfill(71,153,4,15);
}
if(solution[2][1]==1)
{
boundaryfill(111,153,10,15);

}
else
{
boundaryfill(111,153,4,15);
}

if(solution[2][2]==1)
{
boundaryfill(153,153,10,15);

}
else
{
boundaryfill(153,153,4,15);
}
if(solution[2][3]==1)
{
boundaryfill(183,153,10,15);

}
else
{
boundaryfill(183,153,4,15);
}
if(solution[2][4]==1)
{
boundaryfill(218,153,10,15);

}
else
{
boundaryfill(218,153,4,15);
}
//////////////////////////////////////////////////
if(solution[3][0]==1)
{
boundaryfill(71,183,10,15);

}
else
{
boundaryfill(71,183,4,15);
}
if(solution[3][1]==1)
{
boundaryfill(111,183,10,15);

}
else
{
boundaryfill(111,183,4,15);
}

if(solution[3][2]==1)
{
boundaryfill(153,183,10,15);

}
else
{
boundaryfill(153,183,4,15);
}

if(solution[3][3]==1)
{
boundaryfill(183,183,10,15);

}
else
{
boundaryfill(183,183,4,15);
}

if(solution[3][4]==1)
{
boundaryfill(218,183,10,15);

}
else
{
boundaryfill(218,183,4,15);
}

//////////////////////////////////////////////////
if(solution[4][0]==1)
{
boundaryfill(71,218,10,15);
}
else
{
boundaryfill(71,218,4,15);
}
if(solution[4][1]==1)
{
boundaryfill(111,218,10,15);

}
else
{
boundaryfill(111,218,4,15);
}

if(solution[4][2]==1)
{
boundaryfill(153,218,10,15);

}
else
{
boundaryfill(153,218,4,15);
}

if(solution[4][3]==1)
{
boundaryfill(183,218,10,15);

}
else
{
boundaryfill(183,218,4,15);
}

if(solution[4][4]==1)
{
boundaryfill(218,218,10,15);

}
else
{
boundaryfill(218,218,4,15);
}




delay(7000);



    return 0;
}
