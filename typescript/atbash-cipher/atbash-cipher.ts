function encodeChar(ch: string): string|null {
  const ord = ch.toLowerCase().charCodeAt(0);
  if (ord < 'a'.charCodeAt(0) || ord > 'z'.charCodeAt(0)) {
    if (ord >= '0'.charCodeAt(0) && ord <= '9'.charCodeAt(0)) {
      return ch;
    }
    return null;
  }
  return String.fromCharCode('z'.charCodeAt(0) - ord + 'a'.charCodeAt(0));
}

function encodeStr(str: string): string {
  return str.split('').map(encodeChar).filter(Boolean).join('');
}


 export function encode(plainText: string): string {
  const cipher = encodeStr(plainText);

  const op = [];

  for (let i = 0; i < cipher.length; i+=5) {
    op.push(cipher.substring(i, i+5));
  }
  return op.join(" ");
}

export function decode(cipherText: string): string {
  return encodeStr(cipherText);
}
