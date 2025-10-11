// Association represents a relationship between two classes where one object uses, communicates with, or references another.

// “One object need to know about the existence of another object to perform its responsibilities”

class Driver {
    private name: string;

    constructor(name: string) {
        this.name = name;
    }
}

class Car {
    private driver: Driver;  // Car has-a Driver

    constructor(driver: Driver) {
        this.driver = driver;
    }

    drive(): void {
        console.log(`${this.driver} is driving the car.`);
    }
}

// Bidirectional Association In a bidirectional association, both classes are aware of each other and can reference one another.

// class Author {
//     private name: string;
//     private books: Book[] = [];

//     addBook(book: Book): void {
//         this.books.push(book);
//         book.setAuthor(this);  // Set the reverse association
//     }
// }

// class Book {
//     private title: string;
//     private author: Author;

//     setAuthor(author: Author): void {
//         this.author = author;
//     }
// }