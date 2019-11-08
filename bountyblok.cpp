#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>

using namespace eosio;

class [[eosio::contract("bountyblok")]] bountyblok : public contract {
  public:
  	using contract::contract;

	// notifying actions
	[[eosio::action]]
	void execchlgdone(name receiver, name account_name, std::string challenge_name, std::string challenge_guid, uint64_t create_date, asset reward) {
		
		// notify receiver using require_recipient via inline action
		notify_challenge_done_action notichlgdone(get_self(), {get_self(), "active"_n});
		notichlgdone.send(receiver, account_name, challenge_name, challenge_guid, create_date, reward);
	}

	[[eosio::action]]
	void notichlgdone(name receiver, name account_name, std::string challenge_name, std::string challenge_guid, uint64_t create_date, asset reward) {
		require_auth(get_self());
		require_recipient(receiver);
	}
	
	// empty log actions
	[[eosio::action]]
	void logtask(std::string task_guid, std::string task_data, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addtask(std::string task_guid, std::string task_data, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addchallenge(std::string challenge_guid, std::string challenge_data, std::string account_name, std::string create_date) {}

	[[eosio::action]]
	void addsocial(std::string from, std::string to, std::string social_data, std::string create_date) {}
	
	// action wrappers
	using notify_challenge_done_action = action_wrapper<"notichlgdone"_n, &bountyblok::notichlgdone>;
};

