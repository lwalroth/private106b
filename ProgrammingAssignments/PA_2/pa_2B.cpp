
// Assignment #2B: Maze

#include "genlib.h"
#include "simpio.h" 
#include "map.h" 
#include "grid.h" 
#include "maze.h" 
#include "vector.h"
#include "random.h"
#include <iostream>
#include "strutils.h"
#include "graphics.h"
#include "extgraph.h"
#include "stack.h"
#include "queue.h"
#include "set.h"


pointT valueToPoint(int value, Maze maze){
	pointT pointVal;
	pointVal.row = value / maze.numCols();
	pointVal.col = value % maze.numCols();
	return pointVal;
}

int pointToValue(pointT pointVal, Maze maze){
	int value = pointVal.col + (maze.numCols() * pointVal.row);
	return value;
	
}



Vector<pointT> getNeighbours(pointT currentPoint, Maze maze) {
	Vector<pointT> deltas;
	pointT d0,d1,d2,d3;
	d0.row = -1; d0.col = 0;
	d1.row = 1; d1.col = 0;
	d2.row = 0; d2.col = 1;
	d3.row = 0; d3.col = -1;
	deltas.add(d0); deltas.add(d1); deltas.add(d2); deltas.add(d3);
	
	Vector<pointT> possibleNeighbours;
	
	for(int i = 0; i < deltas.size(); i++){
		pointT nextPoint;
		nextPoint.row = deltas[i].row + currentPoint.row;
		nextPoint.col = deltas[i].col + currentPoint.col;
		
		if (maze.pointInBounds(nextPoint)){
			possibleNeighbours.add(nextPoint);
		}
	}
	return possibleNeighbours;
}

pointT getRandomNeighbour(pointT currentPoint, Maze maze){
	
	Vector<pointT> possibleNeighbours = getNeighbours(currentPoint, maze);
	int randIndex = RandomInteger(0, possibleNeighbours.size()-1);
	pointT newNeighbour = possibleNeighbours[randIndex];
	
	
	return newNeighbour;
	
}

Vector<pointT> getAllNeighbours(pointT currentPoint, Maze maze){
	
	Vector<pointT> allNeighbours = getNeighbours(currentPoint, maze);
	for(int i = allNeighbours.size()-1; i >= 0; i--){
		if(maze.isWall(currentPoint, allNeighbours[i])){
			allNeighbours.removeAt(i);
			
		}
	}
	return allNeighbours;
	
}		   
		

void generateMaze(Maze &maze){
	Set<int>visited;
	int numCells = maze.numRows() * maze.numCols();
	int startCell = RandomInteger(0, numCells-1);
	
	
	
	pointT startPoint = valueToPoint(startCell, maze);
	
	//cout << "StartCell: " << startCell <<  " numCells: " << numCells << endl; 
	//cout << " (" <<  startPoint.row << " , " << startPoint.col << ")" << endl; 
	
	visited.add(startCell);
	
	while(visited.size() < numCells){
		
		pointT nextNeighbour = getRandomNeighbour(startPoint, maze);
		int valueNextNeighbour = pointToValue(nextNeighbour,maze);
		
		//cout << "(" << nextNeighbour.row << ", " << nextNeighbour.col << ")" << endl;
		
		if(!visited.contains(valueNextNeighbour)){
			maze.setWall(startPoint, nextNeighbour,false);
			visited.add(valueNextNeighbour);
			
		}
		startPoint = nextNeighbour;
	}
}

bool atGoal(int point, Maze maze){
	
	pointT goal; 
	goal.row = maze.numRows()-1;
    goal.col = maze.numCols()-1;
	int goalCell = pointToValue(goal, maze);
	if(goalCell == point){
		return true;
	} else {
		return false;
	}
}


	
Stack<pointT> findShortestPath(Maze &maze){
	pointT startLocation;
	startLocation.row = 0;
	startLocation.col = 0;
	
	Queue<Stack<pointT> > q;
	Stack<pointT> stack;
	
	stack.push(startLocation);
	q.enqueue(stack);
	
	Set<int> visited;
    int startLocationCell = pointToValue(startLocation, maze);
    visited.add(startLocationCell);
	Stack<pointT> currentPath;
	
	while(!q.isEmpty()){
		currentPath = q.dequeue();
		pointT topPoint = currentPath.peek(); //check this, you may need .pop()
		int currentPathCell = pointToValue(topPoint, maze);
		if(atGoal(currentPathCell,maze)) break;
		
		Vector<pointT> neighbours = getAllNeighbours(topPoint, maze);
		
		
		for(int i = 0; i < neighbours.size(); i++){
			int neighboursCell = pointToValue(neighbours[i], maze);
			if (!visited.contains(neighboursCell)) {  
				
				visited.add(neighboursCell);
				
				Stack<pointT> pathCopy; 
				pathCopy = currentPath;
				pathCopy.push(neighbours[i]);
				q.enqueue(pathCopy);	
			}
		}
	}
	return currentPath;
}
	
int main(){
	
	cout << "Enter the number of maze rows: " << endl; 
	int mazeRows = GetInteger(); 
	cout << "Enter the number of maze columns: " << endl; 
	int mazeCols = GetInteger();
	
	Maze curMaze(mazeRows,mazeCols,true); 
	
	curMaze.draw();
	
	generateMaze(curMaze);
	
	Stack<pointT> shortestPath = findShortestPath(curMaze); 
	
	pointT pt; 
	while ( !shortestPath.isEmpty() ) { 
		pt = shortestPath.pop(); 
		curMaze.drawMark(pt,"Blue"); 
	}
	
	
	//curMaze.draw(); 
	
	
	/*Stack<pointT> shortestPath = findShortestPath(curMaze);
	while(!shortestPath.isEmpty()){
		pointT curpt = shortestPath.pop();
		cout << curpt.row << " , " << curpt.col << endl;
		
	}
	 */
	
	/* pointT point;
	point.row = 5;
	point.col = 4;
	Vector<pointT> vec = getAllNeighbours(point,curMaze);
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i].row << "," << vec[i].col << endl;
	}
	*/
	
	
	
	
	
	return 0;
}



