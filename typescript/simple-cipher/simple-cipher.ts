export class SimpleCipher {
  public key: string;

  constructor(key: null | string = null) {
    this.key = key || SimpleCipher.randomKey();
  }

  static randomKey(): string {
    return [...Array(100)]
      .map(() => Math.floor(Math.random() * 26 + 'a'.charCodeAt(0)))
      .map((ord) => String.fromCharCode(ord))
      .join('');
  }

  cypher(): number[] {
    return this.key.split('').map((ch) => ch.charCodeAt(0) - 'a'.charCodeAt(0));
  }

  encode(plainText: string): string  {
    return plainText.split('')
      .map((ch, n) => ch.charCodeAt(0) + this.cypher()[n % this.key.length])
      .map((ord) => ord > 'z'.charCodeAt(0) ? ord - 26 : ord)
      .map((ord) => String.fromCharCode(ord))
      .join('');
  }

  decode(encodedText: string): string {
    return encodedText.split('')
      .map((ch, n) => ch.charCodeAt(0) - this.cypher()[n % this.key.length])
      .map((ord) => ord < 'a'.charCodeAt(0) ? ord + 26 : ord)
      .map((ord) => String.fromCharCode(ord))
      .join('');
  }
}
