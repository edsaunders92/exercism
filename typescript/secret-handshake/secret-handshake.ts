export function commands(n: number) {
  const handshake = ['wink', 'double blink', 'close your eyes', 'jump'].filter((_,i) => (n >> i) % 2);

  if (n >> 4) {
    handshake.reverse();
  }
  return handshake;
}
