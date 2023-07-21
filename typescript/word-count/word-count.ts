function ord(ch: string): number {
  return ch.charCodeAt(0);
}

function isAlphaNumeric(ch: string): boolean {
  const n = ord(ch);
  return (n >= ord('a') && n <= ord('z') || (n >= ord('0') && n <= ord('9')));
}


export function count(text: string): Map<string, number> {
  const dict: Map<string, number> = new Map<string, number>();

  // Loop through the text
  text = text.toLowerCase() + '\n';
  let left: number = 0;
  for (let right: number = 0; right < text.length; right++) {
    const ch: string = text[right];
    if (isAlphaNumeric(ch) || ch == "'") {
      continue;
    }

    if (left == right) {
      left = right + 1;
      continue;
    }

    let word: string = text.substring(left, right);

    if (text[left] == "'" && text[right - 1] == "'" ) {
      if (right - 2 < left) {
        left = right + 1;
        continue;
      }
    }

    if (text[left] == "'") { 
      word = text.substring(left + 1, right);
      left += 1;
    }
    if (text[right - 1] == "'") { 
      word = text.substring(left, right - 1);
    }

    dict.set(word, (dict.get(word) || 0) + 1);

    left = right + 1;
  }
  return dict;
}
