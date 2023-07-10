
function dnaToRna(nuc: string): string {
  switch (nuc) {
    case     'G': return 'C';
    case     'C': return 'G';
    case     'T': return 'A';
    case     'A': return 'U';
    default: throw 'Invalid input DNA.';
  }
}

export function toRna(sequence: string) {
  return sequence.split('').map(dnaToRna).join('');
}
