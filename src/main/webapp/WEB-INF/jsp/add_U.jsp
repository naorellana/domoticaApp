<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"   %>
<%@taglib  prefix="form" uri="http://www.springframework.org/tags/form" %>
<jsp:include page="header.jsp" />


<div class="creaUsuario container">
	<form action="${action}">
	<div class="form-group">
            <label for="id">ID</label>
    <input type="number" class="form-control" name="id"  placeholder="Enter ID" value="${usuarios.id}">
    </div>
		<div class="form-group">
    <label for="nombre">Nombre</label>
    <input type="text" class="form-control" name="nombre"  placeholder="Nombre" value="${usuarios.nombre}">
    </div>
  <div class="form-group">
    <label for="correo">Email address</label>
    <input type="email" class="form-control" name="correo" aria-describedby="emailHelp" placeholder="Enter email" value="${usuarios.correo }">
    <small name="emailHelp" class="form-text text-muted">We'll never share your email with anyone else.</small>
  </div>
  <div class="form-group">
    <label for="telefono">Teléfono</label>
    <input type="number" class="form-control" name="telefono" placeholder="Teléfono" value="${usuarios.telefono}">
  </div>
  <div class="form-group">
    <label for="rol">Permisos</label>
    <select class="custom-select" name="rol">
        <option value="0">Administrador</option>
        <option value="1">Cliente</option>
      </select>
  </div>
  <div class="form-group">
    <label for="estado">Estado</label>
    <select class="custom-select" name="estado">
        <option value="0">Insolvente</option>
        <option value="1">Solvente</option>
      </select>
  </div>
  
  <button type="submit" class="btn btn-primary">Guardar</button>
</form>
</div>




<jsp:include page="footer.jsp" />
