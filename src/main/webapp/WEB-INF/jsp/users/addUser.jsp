<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"   %>
<%@taglib  prefix="form" uri="http://www.springframework.org/tags/form" %>
<jsp:include page="../header.jsp" />


<div class="creaUsuario">
	<form action="${action}">
	<div class="form-group">
    <input type="hidden" class="form-control" name="ID_USR"  placeholder="Enter user" value="1">
    </div>
		<div class="form-group">
    <label for="USUARIO">Usuario</label>
    <input type="text" class="form-control" name="USUARIO"  placeholder="Enter user" value="${usuarios.USUARIO}">
    </div>
  <div class="form-group">
    <label for="MAIL">Email address</label>
    <input type="email" class="form-control" name="MAIL" aria-describedby="emailHelp" placeholder="Enter email" value="${usuarios.MAIL }">
    <small name="emailHelp" class="form-text text-muted">We'll never share your email with anyone else.</small>
  </div>
  <div class="form-group">
    <label for="PASSWD">Password</label>
    <input type="password" class="form-control" name="PASSWD" placeholder="Password" value="${usuarios.PASSWD}">
  </div>
  <div class="form-group">
      <label for="ID_ROLE">ID_ROLE</label>
    <input type="number" class="form-control" name="ID_ROLE"  placeholder="Enter Reole(1)" value="${usuarios.ID_ROLE}">
    </div>
  <button type="submit" class="btn btn-primary">Submit</button>
</form>
</div>

<jsp:include page="../footer.jsp" />
