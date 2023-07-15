export class Rational {
  public numerator: number;
  public denominator: number;

  constructor(numerator: number, denominator: number) {
    this.numerator = numerator;
    this.denominator = denominator;
  }

  add(other: Rational): Rational {
    this.numerator = other.numerator * this.denominator + this.numerator * other.denominator;
    this.denominator *= other.denominator;
    this.reduce();
    return this;
  }

  sub(other: Rational): Rational {
    this.numerator = this.numerator * other.denominator - other.numerator * this.denominator;
    this.denominator *= other.denominator;
    this.reduce();
    return this;
  }

  mul(other: Rational): Rational {
    this.numerator *= other.numerator;
    this.denominator *= other.denominator;
    this.reduce();
    return this;
  }

  div(other: Rational): Rational {
    this.numerator *= other.denominator;
    this.denominator *= other.numerator;
    this.reduce();
    return this;
  }

  abs(): Rational {
    this.reduce();
    this.numerator = Math.abs(this.numerator);
    return this;
  }

  exprational(n: number): Rational {
    this.numerator = this.numerator ** n;
    this.denominator = this.denominator ** n;
    return this;
  }

  expreal(n: number): number {
    return Math.pow(n, this.toFloat());
  }

  reduce(): Rational {
    let a = Math.abs(this.numerator);
    let b = Math.abs(this.denominator);
    while (b) {
      [a, b] = [b, a % b];
    }
    this.numerator = Math.floor(this.numerator / a);
    this.denominator = Math.floor(this.denominator / a);

    if (this.denominator <= 0) {
      this.numerator *= -1;
      this.denominator *= -1;
    }
    return this;
  }
  
  toFloat(): number {
    return this.numerator / this.denominator;
  }
}
