<br>
<br>
<br>
<br>
<br>
  <footer class="page-footer orange">
    <div class="footerNavbar">
      <nav class="navbar fixed-bottom navbar-light bg-light">
  <a class="navbar-brand" href="#">Fixed bottom</a>
</nav>
    </div>
  </footer>


  <!--  Scripts-->
  <script>
function confirmar() {
  if(confirm("Do you really want to do this?"))
    document.forms[0].submit();
  else
    return false;
}
</script>
<script>
     $('.datepicker').pickadate({
    selectMonths: true, // Creates a dropdown to control month
    selectYears: 15, // Creates a dropdown of 15 years to control year,
    today: 'Today',
    clear: 'Clear',
    close: 'Ok',
    closeOnSelect: false, // Close upon selecting a date,
    format: "yyyy/mm/dd"
  });
</script>
<!--
<script src="/js/jquery-3.3.1.min.js"></script>
<script src="/js/init.js"></script>
<script src="/js/initDate.js"></script> -->
<script src="/js/bootstrap.min.js"></script>
<script src="/js/bootstrap.js"></script>

  </body>
</html>