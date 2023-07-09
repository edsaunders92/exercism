use std::collections::HashSet;
use std::char::ToLowercase;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a[&str]) -> HashSet<&'a str> {
    // Sort word
    let mut lowercase : Vec<_> = word.chars().map(|ch| ch.to_lowercase()).flatten().collect();
    let mut sorted = lowercase.clone();
    sorted.sort();

    HashSet::from_iter(
        possible_anagrams.into_iter()
        .filter(|candidate| {
    let mut candidate_lower : Vec<_> = word.chars().map(|ch| ch.to_lowercase()).flatten().collect();
    let mut candidate_sorted = candidate_lower.clone();
    sorted.sort();
        })
        .map(|candidate| *candidate)
    )
}
