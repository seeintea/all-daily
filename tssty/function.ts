function add(x: number, y: number) :number {
    return x+y;
}

let myadd = function (x: number, y: number) :number {
    return x+y;
}

function buildName(firstname: string, lastname?: string): string {
    if(lastname) {
        return firstname + lastname;
    } else {
        return firstname;
    }
}

function buildName1(firstname: string, lastname = "ts"): string {
    return firstname + lastname
}



