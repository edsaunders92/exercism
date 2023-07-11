
const A = 'A'.charCodeAt(0);
const Zero = '0'.charCodeAt(0);

function randomUpper() {
  return String.fromCharCode(Math.floor(Math.random() * 26) + A);
}

function randomDigit() {
  return String.fromCharCode(Math.floor(Math.random() * 10) + Zero);
}

export class Robot {
  protected robotName: string|undefined;
  protected isNamed: boolean = false;
  protected static assignedNames: Set<string> = new Set();

  public get name(): string {
    if (this.robotName) {
      return this.robotName;
    }

    do {
      this.robotName = [randomUpper(), randomUpper(), randomDigit(), randomDigit(), randomDigit()].join('');
    } while (Robot.assignedNames.has(this.robotName));

    Robot.assignedNames.add(this.robotName);
    return this.robotName;
  }

  public resetName(): void {
    this.robotName = undefined;
  }

  public static releaseNames(): void {
    this.assignedNames = new Set();
  }
}
