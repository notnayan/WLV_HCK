package com.question3;

import akka.actor.ActorRef;
import akka.actor.ActorSystem;
import akka.actor.Props;

class Main {

	public static void main(String[] args) {
		ActorSystem system = ActorSystem.create(); // Create an instance of the ActorSystem
		ActorRef bankAccountRef = system.actorOf(Props.create(BankAccount.class)); // Create an ActorRef for the BankAccount actor

		for (int i = 0; i < 10; i++) {
			int random = (int) (Math.random() * 2001) - 1000; // Generate a random value between -1000 and 1000
			if (random < 0) {
				bankAccountRef.tell(new Withdraw(random), ActorRef.noSender()); // Send a Withdraw message to the bankAccountRef ActorRef with the random value as the amount
			} else {
				bankAccountRef.tell(new Deposit(random), ActorRef.noSender()); // Send a Deposit message to the bankAccountRef ActorRef with the random value as the amount
			}
		}

		system.terminate(); // Terminate the ActorSystem
	}

}
