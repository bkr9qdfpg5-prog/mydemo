// Dark mode functionality
document.addEventListener('DOMContentLoaded', function() {
    const darkModeToggle = document.getElementById('dark-mode-toggle');
    
    // Guard clause: ensure element exists
    if (!darkModeToggle) return;
    
    // Check for saved dark mode preference
    let isDarkMode = false;
    try {
        isDarkMode = localStorage.getItem('darkMode') === 'enabled';
    } catch (e) {
        // localStorage may throw in private browsing mode
        console.warn('localStorage not available:', e);
    }
    
    // Apply saved preference
    if (isDarkMode) {
        document.body.classList.add('dark-mode');
        darkModeToggle.checked = true;
    }
    
    // Toggle dark mode
    darkModeToggle.addEventListener('change', function() {
        if (this.checked) {
            document.body.classList.add('dark-mode');
            try {
                localStorage.setItem('darkMode', 'enabled');
            } catch (e) {
                console.warn('Failed to save dark mode preference:', e);
            }
        } else {
            document.body.classList.remove('dark-mode');
            try {
                localStorage.setItem('darkMode', 'disabled');
            } catch (e) {
                console.warn('Failed to save dark mode preference:', e);
            }
        }
    });
});
