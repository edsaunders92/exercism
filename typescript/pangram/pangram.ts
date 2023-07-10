export function isPangram(word: string) {
  const a: number = 'a'.charCodeAt(0);
  const set: boolean[] = Array(26).fill(false);

  word.toLowerCase()
    .split('').map((ch) => ch.charCodeAt(0) - a)
    .filter((ch) => !(ch < 0))
    .filter((ch) => !(ch >= 26))
    .forEach((ch) => set[ch] = true);

  return set.every(Boolean);
}
