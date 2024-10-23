function processinput() {
    var code = document.getElementById('input').value;
    pass2html('html_output', code)
}

function pass2html(id, code) {
    document.getElementById(id).innerHTML = code
}