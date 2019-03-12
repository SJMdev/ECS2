#include "window.ih"

void Window::drawObject(Object &object)
{
	glActiveTexture(GL_TEXTURE0);
	//calculate object model matrix
	//        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
	object.modelMatrix = object.scaleMatrix * object.rotationMatrix * object.translationMatrix;
	object.normalTransformMatrix = object.modelMatrix.normalMatrix();

	glUniformMatrix4fv(d_modelMatrixLocation, 1, false, object.modelMatrix.data());
	glUniformMatrix3fv(d_normalTransformMatrixLocation, 1, false, object.normalTransformMatrix.data());

	glBindVertexArray(gVAO);
	glBindTexture(GL_TEXTURE_2D, object.TBO);

	glUniform1i(d_textureLocation, 0);
	// SDL_Log("drawObject: object.interleaved_vertices.size: %d", object.interleaved_vertices.size());
	glDrawArrays(GL_TRIANGLES,0, object.interleaved_vertices.size()); //changed

}