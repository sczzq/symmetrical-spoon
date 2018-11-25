1, Introduction
The Paxos algorithm for implementing a fault-tolerant distributed system.
Key Word: fault-tolerant distributed system.
distributed algorithm, consensus algorithm -- synod algorithm

2, The consensus algorithm
The Problem:
	processes to propose values.
	consensus algorithm ensures a single one is chosen.
	if no proposed value, then no value be chosen.
	if a value be chosen, then processes learn the chosen value.

	use another nature language to discrible this:
	一组程序可以提议一些值
	一致性算法保证只有一个值被选择
	如果没有提议的值，那么就没有值被选择
	如果一个值被选择，那么多个程序可以了解到这个值

	一致性算法的安全性保证：
	如果一个值被选择，那么这个值一定是被提议的，
	并且仅仅一个值被选择，
	一个进程不能知道一个值是否被选择，除非这个值真的被选择了

	three classes of agents: proposers, acceptors, learners
	agents may in one process or more processes,

	agents communicate with one another by sending messages.
	customary asynchronous, non-Byzantine model:
		Agents operate at arbitrary speed, may fail by stopping, 
		and may restart. Since all agents may fail after a value
		is chosen and then restart, a solution is impossible
		unless some information can be remembered by an agent
		that has failed and restarted.
		Messages can take arbitrarily long to be delivered,
		can be duplicated, and can be lost, but they are not corrupted.

	towards here, some Key Words:
	consensus, agents, messages, 
	agents: proposers, acceptors, learners.

choosing a value:
	To ensure that only a single value is chosen, we can let a large
	enough set consist of any majority of the agents.
	In the absence of failure or message loss, we want a value to be
	chosen even if only one value is proposed by a single proposer.
	this suggests the requirement:
	P1, an acceptor must accept the first proposal that it receives.
			---> an acceptor must be allowed to accept more than one proposal.
			each proposeres may have each value, may have same value.
			more proposers may been chosen, if they have same value.
	P2, If a proposal with value v is chosen, then every higher-numbered
		proposal that is chosen has value v.
	P2a, if a proposal with value v is chosen, the every higher-numbered proposal
		accepted by any acceptor has value v.
	P2b, if a proposal with value v is chosen, then every higher-numbered
		proposal issued by any proposer has value v.
	P2c, for any v and n, if a proposal with value v and number n is issued,
		then there is a set S consisting of a majority of acceptors such that
		either (a) no acceptor in S has accepted any proposal numbered less
		the n, or (b) v is the value of the highest-numbered proposal among
		all proposals numbered less than n accepted by the acceptors in S.

	P1a, an acceptor can accept a proposal numbered n if it has not 
		responded to a prepare request having a number greater than n.

	So, proposers' algorithm:
		1, A proposer chooses a new proposal number n and sends a request to
			each member of some set of acceptors, asking it to respond with:
			(a) A promise never again to accept a proposal numbered less than
				n, and
			(b) The proposal with the highest number less than n that it has
				accepted, if any.
			call such a request a prepare request with number n.
		2, If the proposer recerives the requested responses from a majority of
			the acceptors, then it can issue a proposal with number n and value
			v, where v is the value of the highest-numbered proposal among the
			response, or is any value seleted by the proposer if the responders
			reported no proposals.
		acceptors' algorithm:
		an acceptor can accept a proposal numbered n if it has not
		responded to a prepare request having a number greater than n.

	toward here, some Key Words:
	proposal number, value number, 
	prepare, promise, accept

	Proposer		    Acceptor
	  |     prepare n      |
	  |    ---------->     |
	  |                    |
	  |     promise n [max]| if has max proposal number.
	  |    <---------      |
	  |                    | 
	  |     accept n v     |
	  |    ---------->     | 
	  |                    | accept n v unless it responsed 
	  |                    | to a prepare request having 
	  |                    | a number greater than n.
	  |                    | 
	  then to say, (n,v) is been chosen.
