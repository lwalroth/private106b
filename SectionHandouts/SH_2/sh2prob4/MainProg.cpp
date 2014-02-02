/*
 *  MainProg.cpp
 *  sh2prob4
 *
 *  Created by athony on 1/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */


#include <iostream> 
#include "genlib.h"
#include "simpio.h"
#include "strutils.h" 
#include "vector.h"
#include "queue.h"
#include "stack.h"
#include <fstream> 
#include "map.h"
#include "grid.h"

struct pointT {
	int row;
	int col;
};

Vector<pointT> makeDeltas(){
	
	Vector<pointT> deltas;
	pointT d0,d1,d2,d3,d4,d5, d6, d7;
	d0.row = -1; d0.col = 0;
	d1.row = 1; d1.col = 0;
	
	d2.row = 0; d2.col = 1;
	d3.row = 0; d3.col = -1;
	
	d4.row = 1; d4.col = -1;
	d5.row = 1; d5.col = 1;
	
	d6.row = -1; d6.col = -1;
	d7.row = -1; d7.col = 1;
	
	
	deltas.add(d0); deltas.add(d1); deltas.add(d2); deltas.add(d3); deltas.add(d4); deltas.add(d5); deltas.add(d6); deltas.add(d7);
	
	return deltas;
}


bool inBounds(Grid<bool> bombLocations, pointT pt){
	if(pt.row >= bombLocations.numRows() ||
	   pt.col >= bombLocations.numCols() ||
	   pt.row < 0 ||
	   pt.col < 0){
		return false;
	}return true;
}

Vector<pointT> getNeighbours(Grid<bool> bombLocations, pointT pt){
	Vector<pointT> deltas = makeDeltas();
	Vector<pointT> neighbourhood;
	
	for(int i =0; i < deltas.size(); i++){
		pointT currpt = deltas[i];
		pointT newpt;
		newpt.row = currpt.row + pt.row;
		newpt.col = currpt.col + pt.col;
		
		if(inBounds(bombLocations, newpt)){
			neighbourhood.add(newpt);
		}
	}
	return neighbourhood;
}

Grid<int> MakeGridOfCounts(Grid<bool> bombLocations){
	
	Grid<int> bombGrid(6,6);
	
	for(int row = 0; row < bombLocations.numRows(); row++){
		for(int col = 0; col < bombLocations.numCols(); col++){
		
			int bombCount = 0;
			if(bombLocations.getAt(row,col) == true){
				bombCount++;
			}
			
			pointT pt;
			pt.row = row;
			pt.col = col;
			
			Vector<pointT> neighbours = getNeighbours(bombLocations, pt);
			
			for(int i = 0; i < neighbours.size(); i++){
				if(bombLocations.getAt(neighbours[i].row, neighbours[i].col)  == true){
					bombCount++;
				}
			}
			bombGrid.setAt(row,col, bombCount);
	
		}
	}
	return bombGrid;
}
		   
		   
		
		   
		


void printGrid(Grid<int> board){
	
	for(int row = 0;  row < board.numRows(); row++){
		
		for(int col = 0; col < board.numCols(); col++){
			cout << board(row,col) << " ";
			

		}
		cout << endl;
		
	}
	
	
}


Grid<bool> bombLocations()
{
	Grid<bool> board (6,6);
	
    for(int row = 0; row < board.numRows(); row++){
		for(int col = 0; col < board.numCols(); col++){
			if(board.getAt(row,col) != true){
				board.setAt(row, col, false);
			}
		}
	
	}
			
	
	board.setAt(0,0, true);
	board.setAt(0,5, true);
	board.setAt(1,5, true);
	board.setAt(2,0, true);
	board.setAt(2,1, true);
	board.setAt(2,3, true);
	board.setAt(2,5, true);
	board.setAt(3,0, true);
	board.setAt(4,2, true);
		

	
	return board;
	
}


	


int main()
{
	Grid<bool> bombs = bombLocations();
	printGrid(MakeGridOfCounts(bombs));
	
	return 0;
	
}