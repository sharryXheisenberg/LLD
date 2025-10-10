// Abstraction is the process of hiding complex internal implementation details and exposing only the relevant, high-level functionality to the outside world. It allows developers to focus on what an object does, rather than how it does it.

// Abstract methods (declared but not implemented)
// Concrete methods (fully implemented)
// Fields and constructors shared across subclasses/

// Multiple classes share some behavior or state

abstract class Vehicle{
    brand : string;

    constructor(brand:string){
        this.brand=brand;
    }

    abstract start():void;

    displayBrand():void{
        console.log(`Brand:${this.brand}`);
    }
}

class Car extends Vehicle{
    constructor(brand:string){
        super(brand);
    }

    start(): void {
        console.log("Car is starting!");
    }
}

let neop = new Car("BMW");
neop.start();
neop.displayBrand();

// 2. Interfaces
// An interface is a pure abstraction. It defines a contract that a class must fulfill but doesn’t provide any implementation. Interfaces are ideal when you want to enforce a consistent API across unrelated classes.

class Document{
    private content:string;

    constructor(content:string){
        this.content = content;
    }

    getContent():string{
        return this.content;
    }
}

interface Printable{
    print(doc:Document):void;
}

class PDFPrinter implements Printable{
    print(doc:Document):void{
        console.log(`Printing PDF: ${doc.getContent()}`);
    }
}

class InkjetPrinter implements Printable{
    print(doc:Document):void{
        console.log(`Printing via Inkjet: ${doc.getContent()}`);
    }
}

let docPDf = new Document("PDF file");
let inkObj = new Document("Ink file");

let newp = new PDFPrinter;
let inkP = new InkjetPrinter;


newp.print(docPDf);

inkP.print(inkObj);


