// Composition is a special type of association that signifies strong ownership between objects. The “whole” class is fully responsible for creating, managing, and destroying the “part” objects. In fact, the parts cannot exist without the whole.

// Key Characteristics of Composition:
// Represents a strong “has-a” relationship.
// The whole owns the part and controls its lifecycle.
// When the whole is destroyed, the parts are also destroyed.
// The parts are not shared with any other object.
// The part has no independent meaning or identity outside the whole.

// In UML class diagrams, composition is represented by a filled diamond (◆) at the “whole” end of the relationship.


class Room{
    private name:string;

    constructor(name:string){
        this.name = name;
    }

    describe():void{
        console.log(`This is ${this.name}`);
    }
}

class House{
    private rooms: Room[];

    constructor(){
        this.rooms = [];
        this.rooms.push(new Room("Living room"));
        this.rooms.push(new Room("bedroom"));
        this.rooms.push(new Room("kitchen"));
    }

    showHouseLayout():void{
        for(const room of this.rooms){
            room.describe();
        }
    }
}
