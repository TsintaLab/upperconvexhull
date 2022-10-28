#include <iostream>
#include <list>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
};

bool comparePoints(Point i1, Point i2)
{
    return (i1.x < i2.x);
};

// int orientation(Point p, Point q, Point r)
// {	
    // int sigma = ((q.y - p.y) / (q.x - p.x));
	// int thau = ((r.y - q.y) / (r.x - q.x));
// cout<<"thau"<<thau<<" "<<"sigma"<< sigma<< endl;
    // if(sigma>thau) return 1;  //clockwise
	// if(thau>sigma) return 0; // counterclock wise
// };

int orientation2(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise 
}


int main()
{
	//A set P of points in the plane
    Point points[] = {{0, 3}, {1, 1}, {2,5}, {2, 2}, {4, 4},
	{1, 0}, {1, 2}, {3, 1}, {3, 3}};
	
	// Point points[] = {{0, 3}, {1, 1}, {2,5}, {2, 2}, {4, 4},
	// {1, 0}, {1, 2}, {3, 1}, {3,5}, {3, 3}};

					  
	int n = sizeof(points)/sizeof(points[0]);
	
	sort(points, points + n, comparePoints);
 
    for (int i = 0; i < n; i++)			
	{		
	cout<<"Lista ordenada" << '('<< points[i].x << ',' << points[i].y << ')' << endl;	
	}
	
/*           Put the points p1 and  p2 in a list Lupper , with p1 as the first point          */	
	vector <Point> Lupper;
	
	Lupper.push_back(points[0]);
	Lupper.push_back(points[1]);
	
    int j = 0;
	for (int i = 2; i<n; i++)
	{
	Lupper.push_back(points[i]);

	while (Lupper.size()> 2 && orientation2(Lupper.at(Lupper.size()-3),Lupper.at(Lupper.size()-2),Lupper.at(Lupper.size()-1))!=1)
	{
    Lupper.erase(Lupper.end()-2);
	j++;
	// cout<<"j"<< j<<endl;
	}
	}

	for (int i = 0; i<Lupper.size(); i++)
	{
		cout<<"Lupper("<<Lupper[i].x<<","<<Lupper[i].y<<")"<<endl;
	}
	
/*           Put the points pn and  pn-1 in a list Llower , with pn as the first point          */
    vector <Point> Llower;
	
	Llower.push_back(points[n-1]);
	Llower.push_back(points[n]);
	
	int j1 = 0;
	for (int i = n-1; i>=0; i--)
	{
	Llower.push_back(points[i]);
	while (Llower.size()> 2 && orientation2(Llower.at(Llower.size()-3),Llower.at(Llower.size()-2),Llower.at(Llower.size()-1))!=1)
	{
    Llower.erase(Llower.end()-2);
	j1++;
	// cout<<"j1 "<< j1 <<endl;
	}
	}	
	// for (int i = 0; i<Llower.size(); i++)
	// {
		// cout<<"("<<Llower[i].x<<","<<Llower[i].y<<")"<<endl;
	// }
    Llower.erase(Llower.begin());
    Llower.pop_back();
	
	for (int i=0; i<Llower.size(); i++)
	{
		cout<<"Llower("<< Llower[i].x <<","<<Llower[i].y <<")"<<endl;
	}

/*             Union of the two vector Lupper and Llower           */	
	vector<Point> convexHull;
	for (int i = 0; i<Lupper.size(); i++)
	{
		convexHull.push_back(Lupper[i]);
	}
	for (int i = 0; i<Llower.size(); i++)
	{
		convexHull.push_back(Llower[i]);
	}
	
	for (int i = 0; i<convexHull.size(); i++)
	{
		cout<<"convexhull("<<convexHull[i].x<<","<<convexHull[i].y<<")"<<endl;
	}
}