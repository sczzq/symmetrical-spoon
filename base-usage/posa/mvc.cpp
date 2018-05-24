/* ************************************************************************
 *       Filename:  mvc.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  2017年09月05日 13时50分34秒
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include "mvc.h"

#define MAXBARSIZE 100

using namespace std;

Model::Model(vector<string> partyNames) : parties(partyNames) { 
	for(int i=0; i<parties.size(); ++i){
		votes.push_back(0);
	}
}

void Model::clearVotes() { 
	for(int i=0; i<votes.size(); ++i){
		votes[i] = 0;
	}
}

void Model::changeVote(string party, long vote){
	for(int i=0; i<parties.size(); ++i){
		cout << parties[i] << endl;
		if(parties[i] == party){
			votes[i] = vote;
			break;
		}
	}
	this->notify();
}

vector<long> & Model::makeVoteIterator(){
	return votes;
}

vector<string> & Model::makePartyIterator(){
	return parties;
}

void Model::attach(Observer *s) {
	registry.push_back(s);
}

void Model::detach(Observer *s) {
	registry.erase(find(registry.begin(),registry.end(),s));
}

void Model::notify(){
	for(int i=0; i < registry.size(); ++i){
		registry[i]->update();
	}
}

View::View(Model *m) : myModel(m), myController(NULL) {
	myModel->attach(this);
}

View::~View() { myModel->detach(this); }

void View::update() { this->draw(); }

void View::initialize(){
	myController = makeController();
	this->draw();
}

Controller::Controller(View * v) : myView(v) {
	myModel = myView->getModel();
	myModel->attach(this);
}

Controller::~Controller() { myModel->detach(this); }

Controller * View::makeController() {
	return new Controller(this);
}

void BarChartView::draw(){
	vector<string> & ip = myModel->makePartyIterator();
	vector<long> & iv = myModel->makeVoteIterator();
	vector<long> dl;
	long max = 1;

	for(int i=0; i<iv.size(); ++i){
		if ( iv[i] > max ) max = iv[i];
	}
	for(int i=0; i<iv.size(); ++i){
		dl.push_back((MAXBARSIZE * iv[i]) / max);
	}
	{
		auto it1 = ip.begin();
		auto it2 = dl.begin();
		for(; it1!=ip.end(), it2!=dl.end(); ++it1, ++it2){
			cout << *it1 << ":\t";
			for(int i=0; i<*it2; ++i){
				cout << "-";
			}
			cout << endl;
			// draw something.
		}
	}
}

TableController::TableController(TableView *tv) : Controller(tv) {
	myModel = myView->getModel();
	myModel->attach(this);
}

void TableController::handleEvent ( Event e) {
	int vote=e.getVote();
	string party=e.getParty();
	if(vote >= 0 && party.size() > 0) {
		cout << party << vote << endl;
		myModel->changeVote(party,vote);
	}
}

Controller *TableView::makeController(){
	return new TableController(this);
}

void TableView::draw(){
	vector<string> & ip = myModel->makePartyIterator();
	vector<long> & iv = myModel->makeVoteIterator();

	{
		auto it1 = ip.begin();
		auto it2 = iv.begin();
		for(; it1!=ip.end(), it2!=iv.end(); ++it1, ++it2){
			cout << *it1 << ":\t" << *it2 << endl;
		}
	}
}

int main()
{
	vector<string> parties;
	parties.push_back("black");
	parties.push_back("blue");
	parties.push_back("red");
	parties.push_back("green");
	parties.push_back("oth.");
	Model m(parties);

	TableView *v1 = new TableView(&m);
	v1->initialize();
	BarChartView *v2 = new BarChartView(&m);
	v2->initialize();

	TableController *tc = new TableController(v1);
	while(1){
		Event e;
		cin >> e.party >> e.vote;
		cout << e.party << e.vote << endl;
		tc->handleEvent(e);
	}
}

