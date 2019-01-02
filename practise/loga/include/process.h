
namespace loga {

class Step;
class Process;

class Step {
public:
	int name;
	vector<int> fields;
};

class Process {
public:
	// name of this process,
	// get from config file.
	int name;
	// field separator of stepname in stepnamelist in config file.
	// this may not need.
	string fs;
	// index of stepname in StepNamesV.
	vector<int> stepnames;
	// whole steps in this process.
	// from config file.
	vector<Step> steps;
	// Linkmap in this process.
	// from config file.
	Linkmap linkmap;
};

class ProcessTemplate {
	string fs;
	string name;
	vector<string> stepnames;
};

// typedef map<string, string> StepNames;

// elements are stepname.
// must keep consistent with each other.
// for search
typedef set<string> StepNamesS;
// for index
typedef vector<string> StepNamesV;

// key is step index,
// value is addition info used by next step, which is extracted from this step.
typedef map<int, vector<int>> Linkmap;

// key is process name in process_template in process.conf.
// value is whole processes in log file, which is extracted from log files though logic in code.
typedef map<string, Process> Processes;

// element of vector is pair of stepname in config file
// key is identify of stepname
// value is acture name of stepname in log file.
typedef vector<map<string, string>> StepNameConf;

// LineField.
// Each line containes LinePattern and MessagePattern.
// LinePattern just has one.
// Each MessageName has one pattern.
// element of vector is map.
// in map:
// key is identify of MessageName.
// value is Message fields, contains LinePattern and MessagePattern.
// example:
//    {
//        {CreateSession, {Time,Source,ThreadID,Level,CreateSession,SessionName,type,Profile}}
//        {AddSession, {Time,Source,ThreadID,Level,AddSession,SessionID}}
//    }
typedef vector<map<string,vector<string,string>>> LineField;

};

