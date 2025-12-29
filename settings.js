// Dark mode functionality
document.addEventListener('DOMContentLoaded', function() {
    const darkModeToggle = document.getElementById('dark-mode-toggle');
    
    // Check for saved dark mode preference
    const isDarkMode = localStorage.getItem('darkMode') === 'enabled';
    
    // Apply saved preference
    if (isDarkMode) {
        document.body.classList.add('dark-mode');
        darkModeToggle.checked = true;
    }
    
    // Toggle dark mode
    darkModeToggle.addEventListener('change', function() {
        if (this.checked) {
            document.body.classList.add('dark-mode');
            localStorage.setItem('darkMode', 'enabled');
        } else {
            document.body.classList.remove('dark-mode');
            localStorage.setItem('darkMode', 'disabled');
        }
    });
});
