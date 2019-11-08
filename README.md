**Bountyblok EOSIO smart contract notification**

bountyblok.io is a gamification engine powered by the EOS blockchain.

Thanks for your support! 

# How It Works

bountyblok.io engine will call an action `execchlgdone` on the chain when a challenge has been completed.

## Challenge Params

- account_name (the account who completed the challenge)
- challenge_name (the name of the completed challenge)
- challenge_guid (the identifier of the challenge)
- reward (the asset associated to the challenge. Example "25.0000 KARMA")
- completion_date (the timestamp of when the challenge was completed)

## Notification

In addition, `execchlgdone` will notify the `receiver` external contract that implements `on_notify` with a carbon copy challenge parameters as shown in [bountyblok::execchlgdone](https://github.com/bountyblok/bountyblok-eos-contract/blob/master/bountyblok.cpp#L18).

[bbreceiver.cpp](https://github.com/bountyblok/bountyblok-eos-contract/blob/master/bbreceiver.cpp) is an example of an external contract on how to define and implement the `on_notify`.

## Use Cases

### karmaapp.io

A daily challenge with 3 tasks:

- Like 3 posts
- Comment 2 posts
- Create 1 post

Reward: 25.0000 KARMA

Everytime an account has completed the above challenge via contract actions executions on chain, bountyblok.io engine will try to notify that contract on chain with the necessary data. (to reward or simply store in a datatable for later).



