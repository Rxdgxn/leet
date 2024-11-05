int minChanges(char* s) {
    int changes = 0;
    
    while (*s) {
        changes += (*s != *(s + 1));
        s += 2;
    }

    return changes;
}