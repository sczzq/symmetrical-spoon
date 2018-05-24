
#ifndef __INFO_H__ZZQ__
#define __INFO_H__ZZQ__

#include "custom.hpp"
#include "connection.hpp"
#include "mapu.hpp"

namespace Anomynous{
	class Info{
		CustomerMap* custmap;
		ConnectionMap* connmap;

		Customer cust {};
		Connection conn {};
	public:
		Info(CustomerMap* custm, ConnectionMap* connm) : custmap{custm}, connmap{connm}{
		}

		int setCustomer(Customer cus){
			cust = cus;
		}
		int setConnection(Connection con){
			conn = con;
		}

		CustomerMap* getCustomerMap() { return custmap; }
		ConnectionMap* getConnectionMap() { return connmap; }
		Customer getCustomer(){
			return cust;
		}
		Connection getConnection(){
			return conn;
		}
	};
};


#endif

