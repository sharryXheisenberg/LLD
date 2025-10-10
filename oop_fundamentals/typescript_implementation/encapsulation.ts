//  Encapsulation is one of the four foundational principles of object-oriented design. It is the practice of grouping data (variables) and behavior (methods) that operate on that data into a single unit (typically a class) and restricting direct access to the internal details of that class.

// Access Modifiers (private, protected, public) Getter and Setters

class BankAccount{
    private balance:number = 0;

    deposit(amount:number):void{
        if(amount<=0){
            throw Error("Deposit amount should be positive!");
        }
        this.balance+=amount;
    }
    withDraw(amount:number):void{
        if(amount<=0){
            throw new Error("Withdrawal amount must be positive");
        }
        if(amount>this.balance){
            throw new Error("Insufficient funds")
        }
        this.balance-=amount;
    }

    getBalance(){
        return this.balance;
    }

}

let newObj = new BankAccount;

console.log(newObj.deposit(100));
console.log(newObj.withDraw(50));
console.log(newObj.getBalance());


class PaymentProcessor {
    private cardNumber: string;
    private amount: number;

    constructor(cardNumber: string, amount: number) {
        this.cardNumber = this.maskCardNumber(cardNumber);
        this.amount = amount;
    }

    private maskCardNumber(cardNumber: string): string {
        return "****-****-****-" + cardNumber.substring(cardNumber.length - 4);
    }

    processPayment(): void {
        console.log(`Processing payment of ${this.amount} for card ${this.cardNumber}`);
    }
}

function main(): void {
    const payment = new PaymentProcessor("1234567812345678", 250.00);
    payment.processPayment();
}

main();