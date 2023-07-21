export const answer = (input: string) => {
  return input.toLowerCase().split(' ')
    .map((word: string) => word === 'plus' ? '+' : word)
    .map((word: string) => word === 'minus' ? '-' : word)
    .filter((word: string) => word.charCodeAt(0) < 'a'.charCodeAt(0) || word.charCodeAt(0) > 'z'.charCodeAt(0) )
    .join(' ');
}
