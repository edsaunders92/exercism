function isWhitespace(ch: string): boolean {
  return ch === ' ' || ch === '\n' || ch === '\t' || ch === '\r';
}

function isUpper(ch: string): boolean {
  return ch >= 'A' && ch <= 'Z';
}

export function hey(message: string): string {
  const _message: string = message.split('').filter((ch) => !isWhitespace(ch)).join('');

  const isYelled = _message === _message.toUpperCase() && _message.split('').filter(isUpper).length > 0;
  const isQuestion = _message.slice(-1) === '?';
  const isSilence = _message.length === 0;

  if (isQuestion && isYelled) {
    return 'Calm down, I know what I\'m doing!'
  }

  if (isQuestion) {
    return 'Sure.';
  }

  if (isYelled) {
    return 'Whoa, chill out!';
  }

  if (isSilence) {
    return 'Fine. Be that way!';
  }

  return 'Whatever.';
}
