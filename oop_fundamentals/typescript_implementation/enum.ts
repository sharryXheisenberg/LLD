// What is an Enum?
// An enum is a special data type that defines a collection of constant values under a single name. Unlike primitive constants or string literals, enums are type-safe, you can’t assign just any value to a variable declared as an enum type.
// Enums are perfect when a variable can only take one out of a small set of predefined values.
// States (e.g., PENDING, IN_PROGRESS, COMPLETED)
// Roles (e.g., ADMIN, CUSTOMER, DRIVER)
// Vehicle Types (e.g., CAR, BIKE, TRUCK)
// Directions (e.g., NORTH, SOUTH, EAST, WEST)

enum OrderStatus {
    PLACED = "PLACED",
    CONFIRMED = "CONFIRMED",
    SHIPPED = "SHIPPED",
    DELIVERED = "DELIVERED",
    CANCELLED = "CANCELLED"
}

const status:OrderStatus = OrderStatus.SHIPPED;

if(status == OrderStatus.SHIPPED){
    console.log("Your pacakge on the way!");
}

//  Enums can have additional data and even behavior. This makes them even more powerful

class Coin{

    static readonly PENNY = new Coin(1);
    static readonly NICKEL = new Coin(5);
    static readonly DIME = new Coin(10);
    static readonly QUARTER = new Coin(25);

    private readonly value:number;

    private constructor(value:number){
        this.value = value;
    }

    getValue():number{
        return this.value;
    }
    static getAllCoins(): Coin[] {
        return [Coin.PENNY, Coin.NICKEL, Coin.DIME, Coin.QUARTER];
    }
    
} 

const total:number = Coin.DIME.getValue() + Coin.QUARTER.getValue();
console.log(total);