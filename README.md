**Bountyblok EOSIO smart contract is powered by the bountyblok.io engine**

The [bountyblok engine](bountyblok.io) will execute on chain the results of a completed challenge.

The account_name, the reward (if any), the challenge name, etc.

In addition, this will notify the external contract that implements the `on_notify` with the results of the challenge.

[bbreceiver.cpp](https://github.com/bountyblok/bountyblok-eos-contract/blob/master/bbreceiver.cpp) is an example of an external contract on how to define and implement the `on_notify`.

