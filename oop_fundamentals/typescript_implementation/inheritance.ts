// Inheritance allows one class (called the subclass or child class) to inherit the properties and behaviors of another class (called the superclass or parent class).
// Inheritance models real-world “is-a” relationships, such as ElectricCar is a Car or Admin is a User

class Car{
    protected make:any;
    protected model:any;
    public price;

    constructor(price:number){
        this.price=price;
    }

    startEngine():void{
        console.log("Engine is started");
    }
    stopEngine():void{
        console.log("Engine is stopping!");
    }
}

class ElectricCar extends Car{
    chargeBatter():void{
        console.log("Battery charging!");
    }

}
class GasCar extends Car {
    fillTank(): void {
        console.log("Filling gas tank");
    }
}
