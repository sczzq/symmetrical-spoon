/* ************************************************************************
 *       Filename:  mvc.h
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年09月05日 14时58分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#ifndef __MVC_H_
#define __MVC_H_

#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Controller;
class View;

class Event{
	public:
		int vote;
		string party;
		int setVote(int v) {
			vote = v;
		}
		int setParty(string p){
			party = p;
		}
		int getVote() { return vote; }
		string getParty() { return party; }
};

class Observer{
	public:
		virtual void update(){ }
};

class Model{
	public:
		Model(vector<string> partyNames);
		void clearVotes();
		void changeVote(string party, long vote);
		vector<long> & makeVoteIterator();
		vector<string> & makePartyIterator();
		void attach(Observer *s);
		void detach(Observer *s);

	protected:
		virtual void notify();
	private:
		vector<long> votes;
		vector<string> parties;
		vector<Observer *> registry;
};

class View : public Observer {
	public:
		View(Model *m);
		virtual ~View();
		virtual void update();
		virtual void initialize();
		virtual void draw() { };
		Controller *makeController();

		Model *getModel() { return myModel; }
		Controller *getController() { return myController; }
	protected:
		Model *myModel;
		Controller *myController;
};

class Controller : public Observer {
	public:
		virtual void handleEvent(Event ) { }
		Controller(View * v);
		virtual ~Controller();
		virtual void update() { }
	protected:
		Model *myModel;
		View *myView;
};

class BarChartView : public View {
	public:
		BarChartView(Model *m) : View(m) { }
		virtual void draw();
};

class TableView : public View {
	public:
		TableView(Model *m) : View(m) { }
		virtual void draw();
		Controller *makeController();
};

class TableController : public Controller {
	public:
		TableController(TableView *tv);
		virtual void handleEvent(Event e);
};


#endif


