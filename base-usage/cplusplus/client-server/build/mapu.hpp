
#ifndef __DATA_STRUCTURE_H__
#define __DATA_STRUCTURE_H__

#include <map>

#include <iostream>
#include <pthread.h>
#include <limits>

#include "random.hpp"
#include "custom.hpp"
#include "connection.hpp"

namespace Anomynous{
	class Customer;

	using mapU = std::map<uint64_t, Customer>;

	class CustomerMap{
		mapU mut;
		/* TODO: no rwlock in stl or boost */
		pthread_rwlock_t rwlock;
	public:
		CustomerMap() {
			pthread_rwlock_init(&rwlock, NULL);
		}

		Customer& make(Customer cust){
			add(cust.getID(), cust);
			return mut.at(cust.getID());
		}

		Customer& make(){
			Customer cust {};
			add(cust.getID(), cust);
			return mut.at(cust.getID());
		}

		/*
		 * return
		 *		true the id is already in map.
		 *		false the is in not in map, and add it to map OK.
		 */
		Customer& add(uint64_t id, Customer cu){
			if(find(id))
				return mut.at(id);
			pthread_rwlock_wrlock(&rwlock);
			mut[id] = cu;
			pthread_rwlock_unlock(&rwlock);
			return mut.at(id);
		}

		Customer& add(Customer cu){
			uint64_t id = cu.getID() ;
			if(find(id)){
				return mut.at(id);
			}
			pthread_rwlock_wrlock(&rwlock);
			mut[id] = cu;
			pthread_rwlock_unlock(&rwlock);
			return mut.at(id);
		}

		bool find(uint64_t id){
			mapU::iterator it;
			pthread_rwlock_rdlock(&rwlock);
			it = mut.find(id);
			if(it != mut.end()){
				pthread_rwlock_unlock(&rwlock);
				return true;
			}
			pthread_rwlock_unlock(&rwlock);
			return false;
		}

		~CustomerMap() {
			pthread_rwlock_destroy(&rwlock);
		}
	};

	using mapC = std::map<uint64_t, Connection>;

	class ConnectionMap{
		mapC mct;
		/* TODO: no rwlock in stl or boost */
		pthread_rwlock_t rwlock;
	public:
		ConnectionMap() {
			pthread_rwlock_init(&rwlock, NULL);
		}

		Connection& make(){
			Connection conn { };
			add(conn.getID(), conn);
			return mct.at(conn.getID());
		}

		Connection& make(Connection conn){
			add(conn.getID(), conn);
			return mct.at(conn.getID());
		}

		/* 
		 * return
		 *		true the id is already in map
		 *		false the id is not already in map, and add it ok
		 */
		bool add(uint64_t id, Connection conn){
			if(find(id))
				return true;
			pthread_rwlock_wrlock(&rwlock);
			mct[id] = conn;
			pthread_rwlock_unlock(&rwlock);
			return false;
		}

		/*
		 * return
		 *		true the id is in map.
		 *		false the id is not in map.
		 */
		bool find(uint64_t id){
			mapC::iterator it;
			pthread_rwlock_rdlock(&rwlock);
			it = mct.find(id);
			if( it != mct.end() ){
				pthread_rwlock_unlock(&rwlock);
				return true;
			}
			pthread_rwlock_unlock(&rwlock);
			return false;
		}

		bool find(Connection& conn){
			uint64_t id = conn.getID();
			return find(id);
		}

		bool del(uint64_t id){
			mapC::iterator it;
			pthread_rwlock_wrlock(&rwlock);
			it = mct.find(id);
			if( it == mct.end() ) {
				pthread_rwlock_unlock(&rwlock);
				return false;
			}
			mct.erase(it);
			pthread_rwlock_unlock(&rwlock);

			return true;
		}

		bool del(Connection& conn){
			uint64_t id = conn.getID();
			return del(id);
		}

		void show(){
			mapC::iterator it, iend;
			pthread_rwlock_rdlock(&rwlock);
			for(it=mct.begin(); it!=mct.end(); ++it)
				cout << it->first << endl;
			pthread_rwlock_unlock(&rwlock);
		}

		size_t size() {
			size_t s;
			pthread_rwlock_rdlock(&rwlock);
			s = mct.size();
			pthread_rwlock_unlock(&rwlock);
			return s;
		}

		~ConnectionMap() {
			pthread_rwlock_destroy(&rwlock);
		}
	};

};

#endif

